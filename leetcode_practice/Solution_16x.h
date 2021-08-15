#pragma once
#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"
#include <unordered_map>

class Solution_16x {
public:
    //169:low方法，利用了限制条件，不过太简单了，没意思
    int majorityElement_by_sort(std::vector<int>& nums);
    //169：摩尔投票法：其实也利用了限制条件，最优解一般都要充分利用限制条件
    //整体思路就是“混战消耗”，因为一方有碾压，极端条件也是它获胜，不极端更是它获胜了，秦灭六国，六国互相打更不行。
    int majorityElement(std::vector<int>& nums);
    
};
