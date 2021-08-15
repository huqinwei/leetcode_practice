#pragma once
//20-29?
#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>





class Solution_2x {
public:
    //20 有效的括号
    bool isValid(std::string s);
    ///
    double newtonSqrt(double n);
    //21:直接迭代遍历即可（方法二：递归）
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    //22.生成括号
    std::vector<std::string> generateParenthesis(int n);

    //24:两两交换链表节点：递归法可能更清晰一点；迭代法：每次跳两个，来回一通指针操作，局部改造，大顺序没变；
    ListNode* swapPairs(ListNode* head);


    //26.删除排序数组中的重复项
    int removeDuplicates(std::vector<int>& nums);




    //27.移除数组元素，隐含条件：超出新长度的数值不关心，双指针相向遍历，对调数值
    int Solution_2x::removeElement(std::vector<int>& nums, int val);
};

