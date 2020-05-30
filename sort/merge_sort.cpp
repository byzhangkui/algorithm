#include "util.h"

void merge_sort_implement(std::vector<int>& vec, Range range);
void merge_sort_merge_subsequence(std::vector<int>& vec, Range left, Range right);

void merge_sort(std::vector<int>& vec) {
    merge_sort_implement(vec, Range(0, vec.size() - 1));
}

void merge_sort_implement(std::vector<int>& vec, Range range) {
    //std::cout << range.left << ";" << range.right << std::endl;

    if (range.right > range.left) {
        size_t middle = (range.left + range.right)/2;

        //子序列排序
        Range left = Range(range.left,middle);
        Range right = Range(middle + 1, range.right);
        merge_sort_implement(vec, left);
        merge_sort_implement(vec, right);
        //合并子序列
        merge_sort_merge_subsequence(vec, left, right);
    }
}

void bubble_sort(std::vector<int>& vec, Range range) {
    for (size_t i = range.left; i < range.size(); ++i) {
        for (size_t j = range.left; j < range.size() - 1 - i; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}

//把 vec  [left, right] 内容合并
void merge_sort_merge_subsequence(std::vector<int>& vec, Range left, Range right) {
    std::cout << "merge_sort_merge_subsequence:" << left.left << ";" << right.right << std::endl;
    //这里是有序的，要利用有序的特点
    std::vector<int> temp;
    size_t left_pos = left.left;
    size_t right_pos = right.left;
    while (left_pos <= left.right && right_pos <= right.right) {
        if (vec[left_pos] < vec[right_pos])
        {
            temp.emplace_back(vec[left_pos]);
            ++left_pos;
        }else {
            temp.emplace_back(vec[right_pos]);
            ++right_pos;
        }
    }
    while (left_pos <= left.right) {
        temp.emplace_back(vec[left_pos]);
        ++ left_pos;
    }
    while (right_pos <= right.right) {
        temp.emplace_back(vec[right_pos]);
        ++ right_pos;
    }
    for (size_t i = 0; i < temp.size(); i++)
    {
        vec[left.left + i] = temp[i];
    }
    
    verbose_vector(vec, Range(left.left, right.right));
    //bubble_sort(vec, range);
}



int main()
{
    std::vector<int> vec_to_sort = {16,2,77,29,99,200,1,3,51,22};
    std::vector<int> vec_to_sort_revert = {10,9,8,7,6,5,4,3,2,1};
    verbose_vector(vec_to_sort);
    merge_sort(vec_to_sort);
    verbose_vector(vec_to_sort);
    std::cout << get_count() << std::endl;
    std::cout << get_compare_count() << std::endl;
    return 0;
}