#include <vector>
#include <iostream>

const static int rows = 2;
const static int cols = 3;

void CreateStaticArray() {
  std::cout << "static array" << std::endl;
  int a[2][3] = {1,2,3,4,5,6};
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << a[i][j] << " ";
    }
  }
  std::cout << std::endl;
}

void CreateDynamicArray() {
  std::cout << "dynamic array" << std::endl;
  //创建一个数组，其元素类型为int* 
  int** array = new int*[rows];
  for (int i = 0; i < rows; ++i) {
    array[i] = new int[cols];
  }

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << array[i][j] << " ";
    }
  }

  std::cout << std::endl;

  for (int i = 0; i < rows; ++i) {
    delete[] array[i];
  }

  delete[] array;
}

void CreateByVector() {
  std::cout << "vector array" << std::endl;

  std::vector<std::vector<int> > array(rows, std::vector<int>(cols));

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      std::cout << array[i][j] << " ";
    }
  }
  std::cout << std::endl;
}

int main() {
  CreateStaticArray();
  CreateDynamicArray();
  CreateByVector();

  return 0;
}