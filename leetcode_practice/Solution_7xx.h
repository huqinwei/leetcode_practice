#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


///����700-799��

class Solution_7xx {
public:
    //704 ���ֲ���
    int search(std::vector<int>& nums, int target);


    //746 ��С������¥��
    int minCostClimbingStairs(std::vector<int>& cost);



    //796 ��ת�ַ������ж������ַ����Ƿ�Ϊ��ת�ַ���
    //KMP�㷨��Knuth-Morris-Pratt�ַ��������㷨
    bool rotateString(std::string s, std::string goal);
};

