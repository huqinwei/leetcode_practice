#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


class Solution_18x {
public:


    //189:旋转数组
    //以为是shift，其实是rotate，题意像shift，其实是用技巧rotate
    //大概是先整体翻转，再以k为中心，左右分别翻转
    //直观理解：把数组当作纸条，从k点撕开，左右交换位置
    void rotate(std::vector<int>& nums, int k);


    //217，存在重复元素：用map或者set查重
    //关于位运算之类的取巧解法，这里因为没有特殊前置条件，应该办不到。
    bool containsDuplicate(std::vector<int>& nums);
};

