//
// Created by Robot on 2017/3/12.
//
#include <vector>
#include <limits>
#include <climits>

template<typename V>

void merge(std::vector<V> &arrs, int begin, int middle, int end) {
    int left_arr_len = middle - begin + 1;
    int right_arr_len = end - middle;
    std::vector<V> left_vec(left_arr_len + 1);
    std::vector<V> right_vec(right_arr_len + 1);
    for (int i = 0; i < left_arr_len; ++i) {//middle节点属于左边arr
        left_vec[i] = arrs[begin + i];
    }
    left_vec[left_arr_len] = INT_MAX;
    for (int j = 0; j < right_arr_len; ++j) {
        right_vec[j] = arrs[middle + j + 1];
    }
    right_vec[right_arr_len] = INT_MAX;
    int left_i = 0;
    int right_i = 0;
    for (int k = begin; k <= end; ++k) {
        if (left_vec[left_i] < right_vec[right_i]) {
            arrs[k] = left_vec[left_i];
            ++left_i;
        } else {
            arrs[k] = right_vec[right_i];
            ++right_i;
        }
    }
}

template<typename V>
void mergeSort(std::vector<V> &arrs, int begin, int end) {
    if (begin < end) {
        int middle = (int) (begin + end) / 2;
        mergeSort(arrs, begin, middle);
        mergeSort(arrs, middle + 1, end);
        merge(arrs, begin, middle, end);
    }
}

