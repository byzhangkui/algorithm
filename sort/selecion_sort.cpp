#include "util.h"

void selection_sort(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        size_t index = i;
        for (size_t j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[index])
            {
                index = j;
            }
        }
        std::swap(vec[i], vec[index]);
    }
}

int main()
{
    std::vector<int> vec_to_sort = {16,2,77,29,99,200,1,3,51,22};
    std::vector<int> vec_to_sort_revert = {10,9,8,7,6,5,4,3,2,1};
    verbose_vector(vec_to_sort);
    selection_sort(vec_to_sort);
    verbose_vector(vec_to_sort);
    std::cout << get_count() << std::endl;
    std::cout << get_compare_count() << std::endl;
    return 0;
}