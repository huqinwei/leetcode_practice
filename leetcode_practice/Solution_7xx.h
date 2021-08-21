#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


///所有700-799题

class Solution_7xx {
public:
    //704 二分查找
    int search(std::vector<int>& nums, int target);


    //746 最小花费爬楼梯
    int minCostClimbingStairs(std::vector<int>& cost);



    //796 旋转字符串，判断两个字符串是否互为旋转字符串
    //KMP算法：Knuth-Morris-Pratt字符串查找算法
    bool rotateString(std::string s, std::string goal);
};

