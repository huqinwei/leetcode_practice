#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"
#include <unordered_map>

class Solution_13x {
public:

    //136，找到只出现一次的数字，我认为第一种是一种巧妙的，取巧的解法，如果要练一下其他代码熟练度之类的，可以换个方法
    int singleNumber(std::vector<int>& nums);
    //练手map
    int singleNumber_by_map(std::vector<int>& nums);

};
