#pragma once
//6-69
#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>





class Solution_1xx {
public:
    //122 ������Ʊ�����Զ�ν���
    //�����������⣬û�����ƽ��״������Դ�͸���ۣ�̰���㷨
    //���ж�̬�滮
    int maxProfit_II(std::vector<int>& prices);



    //136���ҵ�ֻ����һ�ε����֣�����Ϊ��һ����һ������ģ�ȡ�ɵĽⷨ�����Ҫ��һ����������������֮��ģ����Ի�������
    int singleNumber(std::vector<int>& nums);
    //����map
    int singleNumber_by_map(std::vector<int>& nums);

    //169:low��������������������������̫���ˣ�û��˼
    int majorityElement_by_sort(std::vector<int>& nums);
    //169��Ħ��ͶƱ������ʵҲ�������������������Ž�һ�㶼Ҫ���������������
    //����˼·���ǡ���ս���ġ�����Ϊһ������ѹ����������Ҳ������ʤ�������˸�������ʤ�ˣ������������������������С�
    int majorityElement(std::vector<int>& nums);


    //165:�Ƚϰ汾�ţ��ַ��������⣿�����������ݹ鷨
    int compareVersion(std::string version1, std::string version2);
    //������
    int compareVersion_iteration(std::string version1, std::string version2);


    //167 ����֮�� II - ������������
    //�ȵ�������ģ��������С�ģ���Ȼ�������ˣ�����һ�������ά�����������������Ҫ������⣺
    //target=54,Ϊʲô4,5,6,,,,,,,40,50,60,�У�50+5����54��Ҫ��j���40����������i���4��
    //����Ĺؼ��������ڡ����򡱣���i��j�Ǵ����࿪ʼ�����ģ����Ⱦ���4+60>54��Ȼ��60�ƶ���50,54���ҵ��ˣ���Ϊ�����л��ǲ�����©�����Բ�����50+5�������
    vector<int> twoSum(vector<int>& numbers, int target);

    //189:��ת����
    //��Ϊ��shift����ʵ��rotate��������shift����ʵ���ü���rotate
    //����������巭ת������kΪ���ģ����ҷֱ�ת
    //ֱ����⣺�����鵱��ֽ������k��˺�������ҽ���λ��
    void rotate(std::vector<int>& nums, int k);


    //198 ��ҽ���
    int rob_II(std::vector<int>& nums);



    //217�������ظ�Ԫ�أ���map����set����
    //����λ����֮���ȡ�ɽⷨ��������Ϊû������ǰ��������Ӧ�ð첻����
    bool containsDuplicate(std::vector<int>& nums);


};

