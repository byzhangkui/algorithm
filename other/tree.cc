#include <iostream>

int binary_tree[] = {31,23,12,66,94,05,17,70,62,49,55,88};
int length = -1;

void trasver(int index);
//
void travserL(int index) {
  int l_index = 2 * index + 1;
  if (l_index < length) {
    trasver(l_index);
  }
}

void travserR(int index) {
  int r_index = 2 * index + 2;
  if (r_index < length) {
    trasver(r_index);
  }
}

void trasverV(int index) {
  if (index < length) {
    std::cout << binary_tree[index] << " ";
  }
}

void trasver(int index) {
  
  travserL(index);
  travserR(index);
  trasverV(index);
}

int main() {
  length = sizeof(binary_tree)/sizeof(int);

  trasver(0);

  return 0;
}