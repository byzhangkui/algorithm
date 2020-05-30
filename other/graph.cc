#include <iostream>
#include <vector>
#include <queue>

const static int rows = 3;
const static int cols = 3;

// A -- B -- E
// |  \ |    |
// D    C    G
// |  /  
// F -- H -- I
//图的数据
//static std::vector<std::vector<char>> graph_value(3, std::vector<char>(3));
static std::vector<char> graph_value(rows * cols);
// 用 0～8 的节点表示图的节点
static std::vector<std::vector<int>> graph_path(9, std::vector<int>(9));
//图访问数据
static std::vector<int> graph_visit(rows * cols);

void InitGraphValue() {
  graph_value[0] = 'A';
  graph_value[1] = 'B';
  graph_value[2] = 'E';
  graph_value[3] = 'D';
  graph_value[4] = 'C';
  graph_value[5] = 'G';
  graph_value[6] = 'F';
  graph_value[7] = 'H';
  graph_value[8] = 'I';
}
// void InitGraphValue() {
//   graph_value[0][0] = 'A';
//   graph_value[0][1] = 'B';
//   graph_value[0][2] = 'E';
//   graph_value[1][0] = 'D';
//   graph_value[1][1] = 'C';
//   graph_value[1][2] = 'G';
//   graph_value[2][0] = 'F';
//   graph_value[2][1] = 'H';
//   graph_value[2][2] = 'I';
// }

void InitGraphPath() {
  graph_path[0][1] = 1;
  graph_path[1][0] = 1;
  graph_path[0][4] = 1;
  graph_path[4][0] = 1;
  graph_path[0][3] = 1;
  graph_path[3][0] = 1;
  graph_path[1][2] = 1;
  graph_path[2][1] = 1;
  graph_path[1][4] = 1;
  graph_path[4][1] = 1;
  graph_path[2][5] = 1;
  graph_path[5][2] = 1;
  graph_path[3][6] = 1;
  graph_path[6][3] = 1;
  graph_path[4][6] = 1;
  graph_path[6][4] = 1;
  graph_path[6][7] = 1;
  graph_path[7][6] = 1;
  graph_path[7][8] = 1;
  graph_path[8][7] = 1;
}

//获取下一个没有被访问过的节点
int GetNext(int node, int current) {
  for (int i = current + 1; i < rows * cols; ++i) {
    if (graph_visit[i] == 0 && graph_path[node][i] == 1) {
      return i;
    }
  }
  return -1;
}



//访问当前节点，并且对下一个节点进行DFS
//由调用方保障当前节点v未
void DFS(int v) {
  std::cout << "visit:" << v << ",value:" << graph_value[v] << std::endl;
  graph_visit[v] = 1;

  int next = GetNext(v, v);
  while (next != -1) {
    if (!graph_visit[next]) {
      DFS(next);
      next = GetNext(v, next);
    } else {
     break; 
    }
  }

}

void DFS() {
  DFS(0);
}

void BFS() {
  std::queue<int> deq;
  deq.push(0);
  graph_visit[0] = 1;

  while (!deq.empty()) {
    int current_node = deq.front();
    deq.pop();
    std::cout << "visit:" << current_node << ",value:" << graph_value[current_node] << std::endl;
    
    int next = -1;
    do {
      next = GetNext(current_node, next);
      if (next != -1) {
        deq.push(next);
        graph_visit[next] = 1;
      }

    } while(next != -1);
  }
}

int main() {
  InitGraphValue();
  InitGraphPath();
  //因为使用了全局变量，DFS和BFS不能同时运行
  //DFS();
  BFS();

}