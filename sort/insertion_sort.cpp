#include "util.h"

//插入排序和冒泡、选择排序最大的不同在于是否会侵入已经排好序的部分
//冒泡、选择排序，已经排好序的部分就是最终结果，接下来的工作都是在未排序区域排序
//插入排序已排序区域还不是最终结果，会侵入已排序区域
void insertion_sort(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        for (size_t j = i; j > 0; --j) {
            if (vec[j] < vec[j - 1]) {
                std::swap(vec[j], vec[j - 1]);
                add_count();
            } else {
                break;
            }

            add_compare_count();
        }
        verbose_vector(vec);
    }
}

int main()
{
    std::vector<int> vec_to_sort = {16,2,77,29,99,200,1,3,51,22};
    std::vector<int> vec_to_sort_revert = {10,9,8,7,6,5,4,3,2,1};
    verbose_vector(vec_to_sort_revert);
    insertion_sort(vec_to_sort_revert);
    verbose_vector(vec_to_sort_revert);
    std::cout << get_count() << std::endl;
    std::cout << get_compare_count() << std::endl;
    return 0;
}