#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


class Solution_21x {
public:



    //217，存在重复元素：用map或者set查重
    //关于位运算之类的取巧解法，这里因为没有特殊前置条件，应该办不到。
    bool containsDuplicate(std::vector<int>& nums);
};

