// 插入排序
// +++++++++++++++++++++++++++++++++++++++++++++++
// + 有序序列 R[0..i-1] | R[i] | 无序序列 R[i+1..n] +
// +++++++++++++++++++++++++++++++++++++++++++++++
// 思想：将 R[i] 插入到有序子序列 R[0..i-1] 中，使记录到有序序列从 R[0..i-1]
// 变为 R[0..i] 步骤： 1、查找 R[i] 到插入位置 k； 2、将 R[k,i-1] 后移一个位置；
// 3、将 R[i] 复制到 R[k] 位置；

#include "util/util.h"

// 升序
// 按照步骤3一步一步来
template <typename T>
void InsectionSort1(T arr[], size_t size) {
  for (size_t i = 1; i < size; ++i) {
    int k = -1;
    for (size_t j = i - 1; j >= 0; --j) {
      if (arr[i] > arr[j]) {
        k = j + 1;
        break;
      }
    }
    T temp = arr[i];
    for (size_t index = i; index > k; --index) {
      arr[index] = arr[index - 1];
    }
    arr[k] = temp;
    LogArray(arr, size);
  }
}

// 先记录 R[i] 的值，然后边比较边移动。找到位置 k 后，直接将 R[i] 移动到 k
template <typename T>
void InsectionSort(T arr[], size_t size) {
  for (int i = 1; i < size; ++i) {
    T temp = arr[i];

    int j = 0;
    for (j = i - 1; j >= 0 && temp < arr[j]; --j) {
      arr[j + 1] = arr[j];
    }

    arr[j + 1] = temp;
  }
}

int main() {
  int arr[] = {1, 3, 5, 7, 9, 8, 6, 4, 2};
  int arr2[] = {1, 3, 5, 7, 9, 8, 6, 4, -1};

  InsectionSort<int>(arr2, sizeof(arr2) / sizeof(int));
  LogArray(arr2, sizeof(arr2) / sizeof(int));
}