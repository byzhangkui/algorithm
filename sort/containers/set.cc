#include <set>
#include <iostream>

int main() {
  std::set<int> my_set;
  auto ret1 = my_set.insert(1);
  std::cout << ret1.second << std::endl;
  auto ret2 = my_set.insert(2);
  std::cout << ret2.second << std::endl;
  auto ret3 = my_set.insert(1);
  std::cout << ret3.second << std::endl;
  std::cout << "set size:" << my_set.size() << std::endl;
  for (const auto& it : my_set) {
    std::cout << it << " ";
  }
  std::cout << std::endl;

  std::multiset<int> my_multi_set;
  my_multi_set.insert(1);
  my_multi_set.insert(2);
  my_multi_set.insert(1);
  std::cout << "multi set size:" << my_multi_set.size() << std::endl;
  for (const auto& it : my_multi_set) {
    std::cout << it << " ";
  }
  std::cout << std::endl;
  return 0;
}