#pragma once
//20-29?
#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>





class Solution_2x {
public:
    //
    bool isValid(std::string s);
    ///
    double newtonSqrt(double n);
    //21:直接迭代遍历即可（方法二：递归）
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    //22.生成括号
    std::vector<std::string> generateParenthesis(int n);
};

