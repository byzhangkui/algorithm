#include <array>
#include <iostream>

int main() {
  std::array<int,3> arr = {1,2,3};

  for (const auto& it : arr) {
    std::cout << it << " ";
  }
  std::cout << std::endl;

  std::cout << "front:" << arr.front() << std::endl;
  arr.front() = 10;
  std::cout << "front:" << arr.front() << std::endl;
  std::cout << "back:" << arr.back() << std::endl;
  int* first = arr.data();
  *first = 4;
  std::cout << "front:" << arr.front() << std::endl;
  ++first;
  *first = 5;
  for (const auto& it : arr) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
}