#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"


class Solution_0x {
public:

    //1.����֮��
    //��ϣ���ֵ䷨�������key��֤����Ҫ���ҵ���
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> twoSum_2points(std::vector<int>& nums, int target);
    std::vector<int> twoSum_brute(std::vector<int>& nums, int target);
    //02:������ӣ�������
    ListNode* addTwoNumbers_iteration(ListNode* l1, ListNode* l2);
    //�ݹ鷨
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);



};
