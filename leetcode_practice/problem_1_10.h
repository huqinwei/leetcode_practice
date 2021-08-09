#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target);

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

};
