#include <string>
#include <iostream>
#include <sstream> // std::stringstream
#include "container_print.hpp"

using namespace std;

int main(int argc, char** argv)
{
  cout << "VECTORS:" << endl;
  vector<bool>   bools   {1,   0,   1,   0,   1,   0  };
  vector<char>   chars   {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<int>    ints    {1,   2,   3,   4,   5,   6  };
  vector<float>  floats  {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  vector<double> doubles {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  // vector<string> strings {"hey", "there", "you", "big", "dirty", "man"};

  cout << "   ints = " << ints    << endl;
  cout << " floats = " << floats  << endl;
  cout << "doubles = " << doubles << endl;
  cout << "  chars = " << chars   << endl;
  cout << "  bools = " << bools   << endl;
  // cout << "strings = " << strings << endl;

  vector< vector<int> > vv { {1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {-1, 0, 1, 0, -1, 0} };
  cout << "\nVECTOR OF VECTORS:\n" << vv << endl;

  array<int, 6> stlarray = {1, 2, 3, 4, 5, 6};
  cout << "\nSTL ARRAY:\n";
  printarr(stlarray);
  cout << endl;

  int cstylearr[] = {1, 2, 3, 4, 5, 6};
  cout << "\nC-STYLE ARRAY:\n";
  printarr(cstylearr, 6);
  cout << endl;

  cout << "\nLISTS:" << endl;
  list<bool>   boolslist   {1,   0,   1,   0,   1,   0  };
  list<char>   charslist   {'a', 'b', 'c', 'd', 'e', 'f'};
  list<int>    intslist    {1,   2,   3,   4,   5,   6  };
  list<float>  floatslist  {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  list<double> doubleslist {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};

  cout << "   ints = " << intslist    << endl;
  cout << " floats = " << floatslist  << endl;
  cout << "doubles = " << doubleslist << endl;
  cout << "  chars = " << charslist   << endl;
  cout << "  bools = " << boolslist   << endl;

  Node<char>* A = new Node<char>('a');
  Node<char>* B = new Node<char>('b');
  Node<char>* C = new Node<char>('c');
  Node<char>* D = new Node<char>('d');
  Node<char>* E = new Node<char>('e');
  Node<char>* F = new Node<char>('f');
  Node<char>* G = new Node<char>('g');
  Node<char>* H = new Node<char>('h');
  Node<char>* I = new Node<char>('i');
  A->L = B;
  A->R = C;
  B->L = D;
  C->L = E;
  C->R = F;
  D->R = G;
  E->R = H;
  F->R = I;

  cout << "\nTREES:" << endl;
  cout << "char tree:" << endl;
  TreePrint<char> TP1(A);
  delete A, B, C, D, E, F, G, H, I;

  cout << "\nint tree:" << endl;
  Node<int>* one = new Node<int>(1);
  Node<int>* two = new Node<int>(2);
  Node<int>* three = new Node<int>(3);
  Node<int>* four = new Node<int>(4);
  Node<int>* five = new Node<int>(5);
  Node<int>* six = new Node<int>(6);
  Node<int>* seven = new Node<int>(7);
  Node<int>* eight = new Node<int>(8);
  Node<int>* nine = new Node<int>(9);
  one->L = two;
  one->R = three;
  two->L = four;
  three->L = five;
  three->R = six;
  four->R = seven;
  five->R = eight;
  six->R = nine;
  TreePrint<int> TP2(one);
  delete one, two, three, four, five, six, seven, eight, nine;

  return 0;
}
