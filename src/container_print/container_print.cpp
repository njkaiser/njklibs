// #include <container_print.hpp>

#include <iostream>
#include <sstream> // std::stringstream
#include <vector>
#include <array>
#include <list>
#include <cassert>

// PRINT VECTOR
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T> &v) {
  out << "{";
  for(size_t i = 0; i < v.size()-1; ++i) {
    out << v[i] << ", ";
  }
  out << v.back() << "}";
  return out;
}

// PRINT VECTOR OF VECTORS
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector< std::vector<T> > &v) {
  out << "{";
  for(size_t i = 0; i < v.size(); ++i) {
    if(i == 0) { out << "{"; }
    else { out << " {"; }
    for(size_t j = 0; j < v[i].size()-1; ++j) {
      out << v[i][j] << ", ";
    }
    if(i == v.size()-1) { out << v[i].back() << "}"; }
    else { out << v[i].back() << "}" << std::endl; }
  }
  out << "}";
  return out;
}

// PRINT C++ STL ARRAY
template<typename T, std::size_t len>
void printarr(const std::array<T, len>& arr) {
  std::cout << "{";
  for(size_t i = 0; i < arr.size()-1; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr.back() << "}";
  return;
}

// PRINT C-STYLE ARRAY
template<typename T>
void printarr(const T arr[], size_t len) {
  std::cout << "{";
  for(size_t i = 0; i < len-1; ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[len-1] << "}";
  return;
}

// PRINT LIST
template<typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T> &l) {
  for(auto it = l.begin(); it != std::next(l.end(), -1); ++it) {
    out << *it << " -> ";
  }
  out << l.back();
  return out;
}


// binary tree node definition
template<typename T>
struct Node {
  T val;
  Node *L;
  Node *R;
  Node(T x) : val(x), L(NULL), R(NULL) {}
};

// metadata for tree printing
template<typename T>
struct Metadata {
  int lat;
  int dep;
  T val;
  int kids;
  Metadata(T v, int l, int d, int k) : val(v), lat(l), dep(d), kids(k) {}
};

// main class for tree printing
template<typename T>
class TreePrint {
public:
  TreePrint(const Node<T>* root);

private:
  int leftmost;
  std::vector< std::vector< Metadata<T> > > output;
  void traverse(const Node<T>* N, const int lat, const int dep);
  void print_tree();
};

template<typename T>
TreePrint<T>::TreePrint(const Node<T>* root) {
  if(root == NULL) { return; } // handle base case of null tree
  leftmost = 0;
  traverse(root, 0, 0);
  print_tree();
}

// PRINT BINARY TREE
template<typename T>
void TreePrint<T>::traverse(const Node<T>* N, const int lat, const int dep) {
  if(N == NULL) { return; } // handle base case of null tree
  if(dep >= output.size()) { output.push_back(std::vector< Metadata<T> >()); }
  if(lat < leftmost) { leftmost = lat; }

  int k;
  if     (N->L == NULL && N->R == NULL) k = 0;
  else if(N->L != NULL && N->R == NULL) k = 1;
  else if(N->L == NULL && N->R != NULL) k = 2;
  else if(N->L != NULL && N->R != NULL) k = 3;
  else assert(0);

  output[dep].push_back(Metadata<T>(N->val, lat, dep, k));
  if(N->L != NULL) { traverse(N->L, lat-1, dep+1); }
  if(N->R != NULL) { traverse(N->R, lat+1, dep+1); }
}

template<typename T>
void TreePrint<T>::print_tree() {
  for(int i = 0; i < output.size(); ++i) {
    int idx1 = 0;
    int idx2 = 0;
    std::stringstream ss1;
    std::stringstream ss2;
    for(int j = 0; j < output[i].size(); ++j) {
      int tmpidx = idx1; // not necessary but I don't feel like fixing right now
      for(int k = 0; k < output[i][j].lat - leftmost - tmpidx; ++k) {
        ss1 << "  ";
        ++idx1;
      }
      tmpidx = idx2; // not necessary but I don't feel like fixing right now
      for(int k = 0; k < output[i][j].lat - leftmost - tmpidx - 1; ++k) {
        ss2 << "  ";
        ++idx2;
      }
      ss1 << output[i][j].val << " ";
      ++idx1;
      switch(output[i][j].kids) {
        case 0: if(output[i][j].lat != leftmost) ss2 << "    ";
                else ss2 << "  ";
                break;
        case 1: ss2 << " /  "; break;
        case 2: if(output[i][j].lat != leftmost) ss2 << "   \\";
                else ss2 << " \\";
                break;
        break;
        case 3: ss2 << " / \\"; break;
        default: assert(0);
      }
      idx2 += 4;
    }
    std::cout << ss1.str() << std::endl;
    if(i != output.size()-1) {
      std::cout << ss2.str() << std::endl;
    }
  }
}
