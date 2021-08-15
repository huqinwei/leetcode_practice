#pragma once
#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"
#include <unordered_map>

class Solution_8x {
public:

    //88  合并两个有序数组，放在nums1，有预留空间\
        输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3\
        输出：[1, 2, 2, 3, 5, 6]
    //类似双指针的思路，可以尾插，如果头插tmp会比较多，最多情况还是相当于整个m都单独存了一份
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);


};
