/* 约瑟夫问题
从n个旅行者中选出一个游客。从第一个人自1开始报数，到第m个出局。下一个人接着从1开始报数。求最后一个人到位置。
 */

#include <iostream>

struct UserNode {
  UserNode() :number(-1), next(nullptr) {}
  int number;
  UserNode* next;
};

int main()
{
  int n = 8, m = 3;
  if (m <= 0 || m <= 0) {
    return -1;
  }

  //构造出n个节点到循环列表
  UserNode* first_node;
  UserNode* current_node;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      first_node = new UserNode;
      first_node->number = i + 1;
      first_node->next = first_node;
      current_node = first_node;
    } else {
      UserNode* new_node = new UserNode;
      new_node->number = i + 1;
      current_node->next = new_node;
      new_node->next = first_node;
      current_node = new_node;
    }
  }

  UserNode* start_node = first_node;
  for (int i = 0; i < n - 1; ++i) {
    //淘汰 n - 1 个人，进行 n - 1 轮
    for (int j = 0; j < m - 2; ++j) {
      start_node = start_node->next;
    }
    //移除下个节点
    UserNode* delete_node = start_node->next;
    start_node->next = delete_node->next;
    std::cout << "remove:" << delete_node->number;
    delete delete_node;
    start_node = start_node->next;
  }

  std::cout << "left:" << start_node->number;
  return 0;
}

//答案