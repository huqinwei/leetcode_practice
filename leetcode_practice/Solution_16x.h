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
    //169:low��������������������������̫���ˣ�û��˼
    int majorityElement_by_sort(std::vector<int>& nums);
    //169��Ħ��ͶƱ������ʵҲ�������������������Ž�һ�㶼Ҫ���������������
    //����˼·���ǡ���ս���ġ�����Ϊһ������ѹ����������Ҳ������ʤ�������˸�������ʤ�ˣ������������������������С�
    int majorityElement(std::vector<int>& nums);
    
};
