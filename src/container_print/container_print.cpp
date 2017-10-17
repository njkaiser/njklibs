//

#include <iostream>
#include <vector>
#include <array>
#include <list>

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
