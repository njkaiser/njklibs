//

#include <iostream>
#include <vector>
#include <array>
#include <list>
#include "container_print.cpp"

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
