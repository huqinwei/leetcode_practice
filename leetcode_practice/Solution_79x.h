#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


class Solution_79x {
public:



    //796 旋转字符串，判断两个字符串是否互为旋转字符串
    //KMP算法：Knuth-Morris-Pratt字符串查找算法
    bool rotateString(std::string s, std::string goal);
};

