#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


class Solution_18x {
public:


    //189:��ת����
    //��Ϊ��shift����ʵ��rotate��������shift����ʵ���ü���rotate
    //����������巭ת������kΪ���ģ����ҷֱ�ת
    //ֱ����⣺�����鵱��ֽ������k��˺�������ҽ���λ��
    void rotate(std::vector<int>& nums, int k);


    //217�������ظ�Ԫ�أ���map����set����
    //����λ����֮���ȡ�ɽⷨ��������Ϊû������ǰ��������Ӧ�ð첻����
    bool containsDuplicate(std::vector<int>& nums);
};

