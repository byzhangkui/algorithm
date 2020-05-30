//单链表倒转

#include <iostream>

struct CNode {
  CNode* next = nullptr;
  int value = 0;
};

CNode* Fun(CNode* pNodeHead) {
  if (pNodeHead == nullptr)
  {
    return nullptr;
  }
  
  CNode* preNode = nullptr;
  CNode* currentNode = pNodeHead;
  CNode* nextNode = nullptr;

  do {
    nextNode = currentNode->next;
    currentNode->next = preNode;
    preNode = currentNode;
    currentNode = nextNode;
  } while(nextNode);

  return preNode;
}

void LogAllNode(CNode* pHead) {
  if (pHead == nullptr) {
    std::cout << "log empty linklist" << std::endl;
    return;
  }

  CNode* temp = pHead;

  while(pHead) {
    std::cout << pHead->value << ","; 
    pHead = pHead->next;
  }

  std::cout << std::endl;
  
}

void LogOneNode(CNode* node) {
  if (node) {
    std::cout << node->value << std::endl;
  }
}

//创建 n 个节点的链表
CNode* GenerateLinkList(size_t nodeNumber) {
  CNode* head = nullptr;
  CNode* current = nullptr;
  for (int i = 0; i < nodeNumber; ++i) {
    CNode* newNode = new CNode;
    newNode->value = i;

    if (head == nullptr) {
      head = newNode;
      current = head;
    } else {
      current->next = newNode;
      current = newNode;
    }
  }  
  return head;
}

int main() {
  std::cout << "empty link list" << std::endl;
  CNode* node0 = GenerateLinkList(0);
  LogAllNode(node0);
  std::cout << "after reverse" << std::endl;
  CNode* node0Reverse = Fun(node0);
  LogAllNode(node0Reverse);
  std::cout << "-------------" << std::endl;

  std::cout << "1 node link list" << std::endl;
  CNode* node1 = GenerateLinkList(1);
  LogAllNode(node1);
  std::cout << "after reverse" << std::endl;
  CNode* node1Reverse = Fun(node1);
  LogAllNode(node1Reverse);
  std::cout << "-------------" << std::endl;

  std::cout << "2 node link list" << std::endl;
  CNode* node2 = GenerateLinkList(2);
  LogAllNode(node2);
  std::cout << "after reverse" << std::endl;
  CNode* node2Reverse = Fun(node2);
  LogAllNode(node2Reverse);
  std::cout << "-------------" << std::endl;

  std::cout << "3 node link list" << std::endl;
  CNode* node3 = GenerateLinkList(3);
  LogAllNode(node3);
  std::cout << "after reverse" << std::endl;
  CNode* node3Reverse = Fun(node3);
  LogAllNode(node3Reverse);
  std::cout << "-------------" << std::endl;

  std::cout << "10 node link list" << std::endl;
  CNode* node10 = GenerateLinkList(10);
  LogAllNode(node10);
  std::cout << "after reverse" << std::endl;
  CNode* node10Reverse = Fun(node10);
  LogAllNode(node10Reverse);
  std::cout << "-------------" << std::endl;

  std::cout << "100 node link list" << std::endl;
  CNode* node100 = GenerateLinkList(100);
  LogAllNode(node100);
  std::cout << "after reverse" << std::endl;
  CNode* node100Reverse = Fun(node100);
  LogAllNode(node100Reverse);
  std::cout << "-------------" << std::endl;
}
//注意事项：
//1、链表为空；
//2、只有1个节点的链表；
//3、第一个节点的next要为空；