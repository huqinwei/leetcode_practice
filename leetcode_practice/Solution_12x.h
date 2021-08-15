#pragma once
//6-69
#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>





class Solution_12x {
public:
    //122 买卖股票：可以多次交易
    //理解题意的问题，没有限制交易次数，自带透视眼，贪心算法
    //还有动态规划
    int maxProfit_II(std::vector<int>& prices);


    //189:旋转数组
    //以为是shift，其实是rotate，题意像shift，其实是用技巧rotate
    //大概是先整体翻转，再以k为中心，左右分别翻转
    //直观理解：把数组当作纸条，从k点撕开，左右交换位置
    void rotate(std::vector<int>& nums, int k);
};

