#pragma once
//6-69
#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>





class Solution_12x {
public:
    //122 ������Ʊ�����Զ�ν���
    //�����������⣬û�����ƽ��״������Դ�͸���ۣ�̰���㷨
    //���ж�̬�滮
    int maxProfit_II(std::vector<int>& prices);


    //189:��ת����
    //��Ϊ��shift����ʵ��rotate��������shift����ʵ���ü���rotate
    //����������巭ת������kΪ���ģ����ҷֱ�ת
    //ֱ����⣺�����鵱��ֽ������k��˺�������ҽ���λ��
    void rotate(std::vector<int>& nums, int k);
};

