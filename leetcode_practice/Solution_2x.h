#pragma once
//20-29?
#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>





class Solution_2x {
public:
    //20 ��Ч������
    bool isValid(std::string s);
    ///
    double newtonSqrt(double n);
    //21:ֱ�ӵ����������ɣ����������ݹ飩
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    //22.��������
    std::vector<std::string> generateParenthesis(int n);

    //24:������������ڵ㣺�ݹ鷨���ܸ�����һ�㣻��������ÿ��������������һָͨ��������ֲ����죬��˳��û�䣻
    ListNode* swapPairs(ListNode* head);


    //26.ɾ�����������е��ظ���
    int removeDuplicates(std::vector<int>& nums);




    //27.�Ƴ�����Ԫ�أ����������������³��ȵ���ֵ�����ģ�˫ָ������������Ե���ֵ
    int Solution_2x::removeElement(std::vector<int>& nums, int val);
};

