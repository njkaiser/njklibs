#include <string>
#include <iostream>
#include <sstream> // std::stringstream
#include "container_print.hpp"

using namespace std;

int main(int argc, char** argv)
{
  // cout << "VECTORS:" << endl;
  // vector<bool>   bools   {1,   0,   1,   0,   1,   0  };
  // vector<char>   chars   {'a', 'b', 'c', 'd', 'e', 'f'};
  // vector<int>    ints    {1,   2,   3,   4,   5,   6  };
  // vector<float>  floats  {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  // vector<double> doubles {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  // // vector<string> strings {"hey", "there", "you", "big", "dirty", "man"};
  //
  // cout << "   ints = " << ints    << endl;
  // cout << " floats = " << floats  << endl;
  // cout << "doubles = " << doubles << endl;
  // cout << "  chars = " << chars   << endl;
  // cout << "  bools = " << bools   << endl;
  // // cout << "strings = " << strings << endl;
  //
  // vector< vector<int> > vv { {1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {-1, 0, 1, 0, -1, 0} };
  // cout << "\nVECTOR OF VECTORS:\n" << vv << endl;
  //
  // array<int, 6> stlarray = {1, 2, 3, 4, 5, 6};
  // cout << "\nSTL ARRAY:\n";
  // printarr(stlarray);
  // cout << endl;
  //
  // int cstylearr[] = {1, 2, 3, 4, 5, 6};
  // cout << "\nC-STYLE ARRAY:\n";
  // printarr(cstylearr, 6);
  // cout << endl;
  //
  // cout << "\nLISTS:" << endl;
  // list<bool>   boolslist   {1,   0,   1,   0,   1,   0  };
  // list<char>   charslist   {'a', 'b', 'c', 'd', 'e', 'f'};
  // list<int>    intslist    {1,   2,   3,   4,   5,   6  };
  // list<float>  floatslist  {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  // list<double> doubleslist {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
  //
  // cout << "   ints = " << intslist    << endl;
  // cout << " floats = " << floatslist  << endl;
  // cout << "doubles = " << doubleslist << endl;
  // cout << "  chars = " << charslist   << endl;
  // cout << "  bools = " << boolslist   << endl;

  Node* A = new Node('a');
  Node* B = new Node('b');
  Node* C = new Node('c');
  Node* D = new Node('d');
  Node* E = new Node('e');
  A->L = B;
  A->R = C;
  B->L = D;
  D->L = E;

  TreePrint TP(A);
  for(int i = 0; i < TP.output.size(); ++i) {
    int idx1 = 0;
    int idx2 = 0;
    stringstream ss1;
    stringstream ss2;
    for(int j = 0; j < TP.output[i].size(); ++j) {
      int tmpidx = idx1; // need a static value while we increment idx1
      for(int k = 0; k < TP.output[i][j].lat - TP.leftmost - tmpidx; ++k) {
        ss1 << ' ';
        // ss2 << ' ';
        ++idx1;
      }
      tmpidx = idx2; // need a static value while we increment idx2
      for(int k = 0; k < TP.output[i][j].lat - TP.leftmost - tmpidx; ++k) {
        // if()
        ss2 << ' ';
        ++idx2;
      }
      ss1 << TP.output[i][j].val;
      ++idx1;
      ss2 << '/';
      ++idx2;
      // cout << TP.output[i][j].val << " ";
    }
    cout << ss2.str() << endl;
    cout << ss1.str() << endl;
    // cout << endl;
  }
  cout << "leftmost: " << TP.leftmost << endl;


  return 0;
}
