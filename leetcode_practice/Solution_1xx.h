#pragma once
//6-69
#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>





class Solution_1xx {
public:
    //122 买卖股票：可以多次交易
    //理解题意的问题，没有限制交易次数，自带透视眼，贪心算法
    //还有动态规划
    int maxProfit_II(std::vector<int>& prices);



    //136，找到只出现一次的数字，我认为第一种是一种巧妙的，取巧的解法，如果要练一下其他代码熟练度之类的，可以换个方法
    int singleNumber(std::vector<int>& nums);
    //练手map
    int singleNumber_by_map(std::vector<int>& nums);

    //169:low方法，利用了限制条件，不过太简单了，没意思
    int majorityElement_by_sort(std::vector<int>& nums);
    //169：摩尔投票法：其实也利用了限制条件，最优解一般都要充分利用限制条件
    //整体思路就是“混战消耗”，因为一方有碾压，极端条件也是它获胜，不极端更是它获胜了，秦灭六国，六国互相打更不行。
    int majorityElement(std::vector<int>& nums);


    //165:比较版本号：字符串处理题？暴力迭代？递归法
    int compareVersion(std::string version1, std::string version2);
    //迭代法
    int compareVersion_iteration(std::string version1, std::string version2);


    //167 两数之和 II - 输入有序数组
    //先迭代减大的，后迭代加小的，虽然做出来了，类似一个有序二维矩阵的搜索，但是需要加深理解：
    //target=54,为什么4,5,6,,,,,,,40,50,60,中，50+5大于54需要让j变成40，而不是让i变成4？
    //这里的关键问题在于“有序”，而i和j是从两侧开始遍历的，会先经历4+60>54，然后60移动到50,54，找到了，因为过程中还是不会遗漏，所以不会有50+5的情况。
    vector<int> twoSum(vector<int>& numbers, int target);

    //189:旋转数组
    //以为是shift，其实是rotate，题意像shift，其实是用技巧rotate
    //大概是先整体翻转，再以k为中心，左右分别翻转
    //直观理解：把数组当作纸条，从k点撕开，左右交换位置
    void rotate(std::vector<int>& nums, int k);


    //198 打家劫舍
    int rob_II(std::vector<int>& nums);



    //217，存在重复元素：用map或者set查重
    //关于位运算之类的取巧解法，这里因为没有特殊前置条件，应该办不到。
    bool containsDuplicate(std::vector<int>& nums);


};

