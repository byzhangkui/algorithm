//斐波那契数列
#include <iostream>

int Fib(int n) {
  if (n < 0) {
    return -1;
  }

  if (0 == n || 1 == n) {
    return n;
  }

  return Fib(n - 1) + Fib(n - 2);
}

int main() {
  std::cout << Fib(0) << std::endl;
  std::cout << Fib(1) << std::endl;
  std::cout << Fib(2) << std::endl;
  std::cout << Fib(3) << std::endl;
  std::cout << Fib(12) << std::endl;
}