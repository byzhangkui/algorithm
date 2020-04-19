#include "util.h"
#include <algorithm>

void quick_sort_impl(std::vector<int>& vec, Range range);
size_t quick_sort_partition(std::vector<int>& vec, Range range);

void quick_sort(std::vector<int>& vec) {
    quick_sort_impl(vec, Range(0, vec.size() - 1));
}


void quick_sort_impl(std::vector<int>& vec, Range range) {
    if (range.left >= range.right) {
        return;
    }

    size_t pivot = quick_sort_partition(vec, range);

    quick_sort_impl(vec, Range(range.left, pivot - 1));
    quick_sort_impl(vec, Range(pivot + 1, range.right));
}

size_t quick_sort_partition(std::vector<int>& vec, Range range) {
    size_t pivot = range.left;//基准点
    size_t left = range.left;
    size_t right = range.right; 

    //将
    while (left < right)
    {
        //从右边找到比基准小的值
        while (left < right && vec[right] >= vec[pivot]) {
            -- right;
        }

        while (left < right && vec[left] <= vec[pivot]) {
            ++ left;
        }
        
        if (left < right) {
            std::swap(vec[left], vec[right]);
        }
    }
    
    if (pivot != left) {
        std::swap(vec[pivot], vec[left]);
    }
    
    verbose_vector(vec,range);

    return left;
}

void quickSort(int left, int right, std::vector<int>& arr)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >= base && i < j)
			j--;
		while (arr[i] <= base && i < j)
			i++;
		if(i < j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	//基准数归位
	arr[left] = arr[i];
	arr[i] = base;
	quickSort(left, i - 1, arr);//递归左边
	quickSort(i + 1, right, arr);//递归右边
}

int main()
{
    std::vector<int> vec_to_sort = {16,2,77,29,99,200,1,3,51,22};
    std::vector<int> vec_to_sort_revert = {10,9,8,7,6,5,4,3,2,1};

    //quickSort(0, vec_to_sort_revert.size() - 1, vec_to_sort_revert);
    //verbose_vector(vec_to_sort_revert);
    quick_sort(vec_to_sort);
    verbose_vector(vec_to_sort);
    std::cout << get_count() << std::endl;
    std::cout << get_compare_count() << std::endl;
    return 0;
}