#include <iostream>
#include <vector>
#include <array>
#include <list>


// PRINT VECTOR
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &v);

// PRINT VECTOR OF VECTORS
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector< std::vector<T> > &v);

// PRINT C++ STL ARRAY
template<typename T, std::size_t len>
void printarr(const std::array<T, len>& arr);

// PRINT C-STYLE ARRAY
template<typename T>
void printarr(const T arr[], size_t len);

// PRINT LIST
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T> &l);


// binary tree node definition
// template<typename T>
struct Node {
  // T val;
  char val;
  Node *L;
  Node *R;
  // Node(T x) : val(x), L(NULL), R(NULL) {}
  Node(char x) : val(x), L(NULL), R(NULL) {}
};

// metadata for tree printing
// template<typename T>
struct Metadata {
  int lat;
  int dep;
  // T val;
  char val;
  // Metadata(int p, int l, T v) : lat(p), dep(l), val(v) {}
  Metadata(char v, int l, int d) : val(v), lat(l), dep(d) {}
};

// template<typename T>
class TreePrint {

public:
  // TreePrint();
  TreePrint(Node* root);
  void traverse(Node* N, int lat, int dep);

// private:
  std::vector< std::vector<Metadata> > output;
  int leftmost;
};
