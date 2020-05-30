#include <iostream> 
#include <sstream>
#include <vector>


#define MY_LOG(x) std::cout << x << std::endl;

template<typename T>
void LogArray(T arr[], size_t size) {
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ',';
    }
    std::cout << std::endl;
}

struct Range{
    Range(int _left, int _right):left(_left),right(_right) 
    {}

    int left;
    int right;
    size_t size() { return right - left + 1; }
};

void verbose_vector(const std::vector<int>& vec) {
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << std::endl;
}

void verbose_vector(const std::vector<int>& vec, const Range& range) {
    for (int i = range.left; i <= range.right; ++i) {
        std::cout << ' ' << vec[i];
    }
    std::cout << std::endl;
}

int exec_count = 0;
int compare_count = 0;

void add_count() {
    ++ exec_count;
}

int get_count() {
    return exec_count;
}

void add_compare_count() {
    ++ compare_count;
}

int get_compare_count() {
    return compare_count;
}