#pragma once
#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"
#include <unordered_map>

class Solution_8x {
public:

    //88  �ϲ������������飬����nums1����Ԥ���ռ�\
        ���룺nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3\
        �����[1, 2, 2, 3, 5, 6]
    //����˫ָ���˼·������β�壬���ͷ��tmp��Ƚ϶࣬�����������൱������m����������һ��
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);


};
