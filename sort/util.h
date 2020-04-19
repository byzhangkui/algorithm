#include <iostream> 
#include <vector>

//template<T>


void verbose_vector(const std::vector<int>& vec) {
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << ' ' << *it;
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