#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"
#include <unordered_map>

class Solution_13x {
public:

    //136���ҵ�ֻ����һ�ε����֣�����Ϊ��һ����һ������ģ�ȡ�ɵĽⷨ�����Ҫ��һ����������������֮��ģ����Ի�������
    int singleNumber(std::vector<int>& nums);
    //����map
    int singleNumber_by_map(std::vector<int>& nums);

};
