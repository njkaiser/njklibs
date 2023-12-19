"""
This tool is useful for finding and replacing text strings in files in a repo.

Usage:
```
python find_and_replace.py
        "string_to_find_in_files"
        "string_you_want_to_replace"
        "string_to_replace_it_with"
        --paths ROOT_DIRECTORY_THAT_YOU_WANT_TO_DO_THE_SEARCH
        --inplace WHETHER_YOU_WANT_TO_DO_A_DRYRUN_OR_THE_ACTUAL_REPLACEMENT
```
Commenly, `string_to_find_in_files` and `string_you_want_to_replace` are
identical, but it's entirely possible you want to constrain them differntly.
If you can't think of a reason to do this, just pretend they're the same :).

Concrete example:
```
python find_and_replace.py
        "foo"
        "foo"
        "bar"
        --paths .
```
Since `inplace` was not explicitly set to true, this command will only execute
a dryrun, printing  all the places in files in the current directly where "foo"
would be replaced with "bar" if we were to add the `--inplace` flag.

It is HIGHLY recommended you run the command in dryrun mode first and verify
the output looks correct before running with `--inplace`
"""

import argparse
import fileinput
import re
import subprocess


# Formatting palette:
PURPLE     = '\033[95m'
CYAN       = '\033[96m'
DARKCYAN   = '\033[36m'
BLUE       = '\033[94m'
GREEN      = '\033[92m'
YELLOW     = '\033[93m'
RED        = '\033[91m'
BOLD       = '\033[1m'
UNDERLINE  = '\033[4m'
END        = '\033[0m'


def parse_args():
    parser = argparse.ArgumentParser()
    parser.add_argument('input', nargs='+')
    parser.add_argument('--inplace', action='store_true', default=False)
    parser.add_argument('--paths', nargs='*')
    # TODO add me in:
    #parser.add_argument('file_pattern', nargs='*')
    args = parser.parse_args()
    return args


def colored_string_from_match_indices(input_string, match_indices, color):
    """
    Replaces the characters in `input_string` between the specified [start,
    stop) indices in `match_indices` with characters of color `color`.

    NOTE: `match_indices` is a list of lists, since there could be multiple
    matches on the same line!
    """
    colored_string = input_string
    for bgn, end in reversed(match_indices):
        colored_string = colored_string[:end] + END + colored_string[end:]
        colored_string = colored_string[:bgn] + color + colored_string[bgn:]
    return colored_string


def find_and_replace(filename, to_match, to_replace_with, inplace):
    if inplace:
        print(f"processing: {filename}")
    else:
        print(f"{GREEN}{BOLD}{UNDERLINE}{filename}{END}")
    
    # Open the file for editing (or just searching, if `inplace` is False).
    with fileinput.FileInput(filename, inplace=inplace) as f:#, backup='.bak') as f:
        for line in f:
            # Find substrings that match our criteria.
            match_indices = [m.span() for m in re.finditer(to_match, line)]
            if match_indices:
                # If we find any matches, replace them with the desired string.
                new_line = re.sub(to_match, to_replace_with, line)
                if inplace:
                    print(new_line, end='')
                else:
                    print(colored_string_from_match_indices(line, match_indices, RED), end='')
                    new_match_indices = [m.span() for m in re.finditer(to_replace_with, new_line)]
                    print(colored_string_from_match_indices(new_line, new_match_indices, BLUE), end='')
            elif inplace:
                print(line, end='')


def main():
    # Parse the command line args.
    args = parse_args()
    find, match, replace = args.input

    # Set up and execute a `git grep` command to find any files we want to
    # process.
    cmd = ["git", "grep", "--name-only", "--full-name", find]
    cmd.extend(args.paths)
    output = subprocess.check_output(cmd).decode('utf-8').strip()
    filenames = output.split('\n')

    # Iterate over the files, either doing replacement or printing what would
    # be replaced, depending on
    for filename in filenames:
        find_and_replace(filename, match, replace, args.inplace)


if __name__ == '__main__':
    main()
