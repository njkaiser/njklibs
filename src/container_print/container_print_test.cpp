#include <string>
#include "container_print.hpp"


int main(int argc, char** argv)
{
  std::cout << "VECTORS:" << std::endl;
  std::vector<bool>   bools   {1,   0,   1,   0,   1,   0  };
  std::vector<char>   chars   {'a', 'b', 'c', 'd', 'e', 'f'};
  std::vector<int>    ints    {1,   2,   3,   4,   5,   6  };
  std::vector<float>  floats  {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  std::vector<double> doubles {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  // std::vector<std::string> strings {"hey", "there", "you", "big", "dirty", "man"};

  std::cout << "   ints = " << ints    << std::endl;
  std::cout << " floats = " << floats  << std::endl;
  std::cout << "doubles = " << doubles << std::endl;
  std::cout << "  chars = " << chars   << std::endl;
  std::cout << "  bools = " << bools   << std::endl;
  // std::cout << "strings = " << strings << std::endl;

  std::vector< std::vector<int> > vv { {1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {-1, 0, 1, 0, -1, 0} };
  std::cout << "\nVECTOR OF VECTORS:\n" << vv << std::endl;

  std::array<int, 6> stlarray = {1, 2, 3, 4, 5, 6};
  std::cout << "\nSTL ARRAY:\n";
  printarr(stlarray);
  std::cout << std::endl;

  int cstylearr[] = {1, 2, 3, 4, 5, 6};
  std::cout << "\nC-STYLE ARRAY:\n";
  printarr(cstylearr, 6);
  std::cout << std::endl;

  std::cout << "\nLISTS:" << std::endl;
  std::list<bool>   boolslist   {1,   0,   1,   0,   1,   0  };
  std::list<char>   charslist   {'a', 'b', 'c', 'd', 'e', 'f'};
  std::list<int>    intslist    {1,   2,   3,   4,   5,   6  };
  std::list<float>  floatslist  {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  std::list<double> doubleslist {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

  std::cout << "   ints = " << intslist    << std::endl;
  std::cout << " floats = " << floatslist  << std::endl;
  std::cout << "doubles = " << doubleslist << std::endl;
  std::cout << "  chars = " << charslist   << std::endl;
  std::cout << "  bools = " << boolslist   << std::endl;

  return 0;
}
