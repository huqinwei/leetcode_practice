#pragma once
#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"


class Solution_0x {
public:

    //1.两数之和
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> twoSum_2points(std::vector<int>& nums, int target);
    std::vector<int> twoSum_brute(std::vector<int>& nums, int target);
    //02:两数相加
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};
