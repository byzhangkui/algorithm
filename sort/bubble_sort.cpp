#include "util.h"
/*

*/
void bubble_sort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        for (size_t j = 0; j < vec.size() - 1 - i; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
                add_count();
            }
            add_compare_count();
        }
    }
}

int main()
{
    std::vector<int> vec_to_sort = {16,2,77,29,99,200,1,3,51,22};
    std::vector<int> vec_to_sort_revert = {10,9,8,7,6,5,4,3,2,1};
    verbose_vector(vec_to_sort);
    bubble_sort(vec_to_sort);
    verbose_vector(vec_to_sort);
    std::cout << get_count() << std::endl;
    std::cout << get_compare_count() << std::endl;
    return 0;
}