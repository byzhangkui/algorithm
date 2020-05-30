//求出1～13的整数中1出现的次数
#include <iostream>

int GetCount(int input) {
  if (input < 1) {
    return 0;
  }

  int a = 0; // 个位
  int b = 0; //10 
  int c = 0; //100
  int number = 0;
  int count = 0;

  do {
    if (++a == 10) {
      a = 0;
      if (++b == 10) {
        b = 0;
        ++c;
      }
    }
    if (1 == a) {
      ++count;
    }
    if (1 == b) {
      ++count;
    }
    if (1 == c) {
      ++count;
    }

   number = a + b * 10 + c * 100; 
  }while(number < input);
  return count;
}

int GetCount(int from, int to) {
  return GetCount(to) - GetCount(from - 1);
}

int Get1Count(int from, int to) {
  if (from <=0 || to <=0 || to < from) {
    return -1;
  }
}

int Get1Count(int input) {
  int ge_wei = -1;
  int others = input;
  int count1 = 0;
  while(others != 0) {
    ge_wei = others % 10;
    others = others / 10;
    if (1 == ge_wei) {
      ++count1;
    }
  }
  return count1;
}


int main() {
  
  std::cout << GetCount(1300) << std::endl;
  std::cout << GetCount(1, 13) << std::endl;
  std::cout << GetCount(100, 1300) << std::endl;
  int count13 = 0;
  for (int i = 1; i <= 999; ++i) {
    count13 += Get1Count(i);
  }
  std::cout << "count13:" << count13 << std::endl;

  int count1300 = 0;
  for (int i = 100; i <= 1300; ++i) {
    count1300 += Get1Count(i);
  }
  std::cout << "count1300:" << count1300 << std::endl;

  std::cout << "Get1Count:" << Get1Count(100) << std::endl;
  return 0;
}