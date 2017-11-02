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
  int kids;
  // Metadata(int p, int l, T v) : lat(p), dep(l), val(v) {}
  Metadata(char v, int l, int d, int k) : val(v), lat(l), dep(d), kids(k) {}
};

// main class for tree printing
// template<typename T>
class TreePrint {
public:
  TreePrint(const Node* root);

private:
  int leftmost;
  std::vector< std::vector<Metadata> > output;
  void traverse(const Node* N, const int lat, const int dep);
  void print_tree();
};
