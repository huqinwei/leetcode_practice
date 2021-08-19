#pragma once

#include "base.h"

class SortCollections {
public:
    //可以参考 https://leetcode-cn.com/problems/sort-an-array/solution/dong-hua-mo-ni-yi-ge-kuai-su-pai-xu-wo-x-7n7g/
    //除了讲解不同排序，和视频演示，还有快速排序的优化思路


    //快速排序
    void Quicksort(int array[], int L, int R);

    //快速排序常规版，瓶颈，遇到1,2,3,4,5,6,.....,49999,50000的时候会很慢，pivot总是取左侧，每层遍历一遍发现不用排，遍历了却不交换，
    //问题不在遍历本身，问题在于，如果以pivot作为分割点去做二分，会导致左侧一直为空，右侧一直满，因为递归的内存开销问题，可能还不如写成普通迭代
    void Quicksort_regular(std::vector<int>& nums, int L, int R);

    //快排优化版
    void Quicksort(std::vector<int>& nums, int L, int R);

    //912：排序数组
    std::vector<int> sortArray_call_Quicksort(std::vector<int>& nums);
    std::vector<int> sortArray(std::vector<int>& nums);
    
};



