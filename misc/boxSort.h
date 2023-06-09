//
// Created by rmesz on 2023. 06. 09..
//

#ifndef MISC_BOXSORT_H
#define MISC_BOXSORT_H


#include <cstddef>
#include <stdexcept>

struct boxSort {
    int* operator()(const int* array, const size_t size) const {
        int max = 0;
        for(size_t i = 0; i < size; ++i) {
            if(array[i] <= 0) throw std::runtime_error("boxSort is only for positive integers!");
            if(array[i] > max) max = array[i];
        }
        int box_array[max+1];
        std::fill_n(box_array, max+1, 0);
        for(size_t i = 0; i < size; ++i) {
            box_array[array[i]] += 1;
        }
        int *result = new int[size];
        int result_idx = 0;
        for(size_t i = 1; i < max + 1; ++i) {
            for(int j = 0; j < box_array[i]; ++j) {
                result[result_idx++] = i;
            }
        }
        return result;
    }
};


#endif //MISC_BOXSORT_H
