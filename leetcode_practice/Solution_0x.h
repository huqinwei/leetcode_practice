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
    //哈希表字典法：如果有key就证明有要查找的数
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> twoSum_2points(std::vector<int>& nums, int target);
    std::vector<int> twoSum_brute(std::vector<int>& nums, int target);
    //02:两数相加：迭代法
    ListNode* addTwoNumbers_iteration(ListNode* l1, ListNode* l2);
    //递归法
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);



};
