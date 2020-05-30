#include <iostream>

int b = 100;

int func(int* p) {//指向相同地址的不同的指针值
  std::cout << "func point's address " << &p << std::endl; //存储指针的地址
  std::cout << "func point point address " << p << std::endl; //指针指向的地址
  std::cout << "func value on point point adress " << *p << std::endl; //指针的值  p = &b;
  return 0;
}

int func1(int*& p) {
  std::cout << "func1 point's address " << &p << std::endl; //存储指针的地址
  std::cout << "func1 point point address " << p << std::endl; //指针指向的地址
  std::cout << "func1 value on point point adress " << *p << std::endl; //指针的值  p = &b;
  return 0;
}

struct Node {
  Node* next;
};

int main() {
  int a = 8;

  //存储 8 的地址
  std::cout << "8's address" << &a << std::endl;

  int* p = &a;
  std::cout << "point's address " << &p << std::endl; //存储指针的地址
  std::cout << "point point address " << p << std::endl; //指针指向的地址
  std::cout << "value on point point adress " << *p << std::endl; //指针的值

  func(p);
  std::cout << "after func " << *p << "," << a << std::endl;

  func1(p);
  std::cout << "after func " << *p << "," << a << std::endl;

  Node* node1 = new Node;
  Node* node2 = new Node;

  Node* head = node1;
  head->next = node2;

  std::cout << "head point's address " << &head << std::endl; //存储指针的地址
  std::cout << "head point point address " << head << std::endl; //指针指向的地址

  std::cout << "node1 point's address " << &node1 << std::endl; //存储指针的地址
  std::cout << "node1 point point address " << node1 << std::endl; //指针指向的地址

  std::cout << "node2 point's address " << &node2 << std::endl; //存储指针的地址
  std::cout << "node2 point point address " << node2 << std::endl; //指针指向的地址  

  std::cout << "head->next point's address " << &head->next << std::endl; //存储指针的地址
  std::cout << "head->next point point address " << head->next << std::endl; //指针指向的地址  

  head = head->next;
  std::cout << "head point's address " << &head << std::endl; //存储指针的地址
  std::cout << "head point point address " << head << std::endl; //指针指向的地址
}

/*
@"head point's address 0x7ffeefbffdb8\r\n" 
@"head point point address 0x100404100\r\n"
@"node1 point's address 0x7ffeefbffdc8\r\n"
@"node1 point point address 0x100404100\r\n"
@"node2 point's address 0x7ffeefbffdc0\r\n"
@"node2 point point address 0x100404110\r\n"
@"head->next point's address 0x100404100\r\n" 
@"head->next point point address 0x100404110\r\n"
@"head point's address 0x7ffeefbffdb8\r\n"  指针的值不会变
@"head point point address 0x100404110\r\n" 指针指向的地址会变
*/