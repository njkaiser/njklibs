#include <iostream>
#include <cstdio>
#include <stdarg.h>
#include "colorprint.h"


#define BLACK "30"
#define RED "31"
#define GREEN "32"
#define GOLD "33"
#define BLUE "34"
#define MAGENTA "35"
#define CYAN "36"
#define WHITE "37"

#define ESC "\033["
#define BOLD "1"
#define END "m"
#define RESET "\033[0m"


void PCYAN(const char* format, ...) {
  std::cout << ESC << CYAN << END;
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  std::cout << RESET;
}

void PGOLD(const char* format, ...) {
  std::cout << ESC << GOLD << END;
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  std::cout << RESET;
}

void PBLUE(const char* format, ...) {
  std::cout << ESC << BLUE << END;
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  std::cout << RESET;
}

void PGREEN(const char* format, ...) {
  std::cout << ESC << GREEN << END;
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  std::cout << RESET;
}

void PMAGENTA(const char* format, ...) {
  std::cout << ESC << MAGENTA << END;
  va_list args;
  va_start(args, format);
  vprintf(format, args);
  va_end(args);
  std::cout << RESET;
}
