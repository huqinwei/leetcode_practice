#pragma once
#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"
#include <unordered_map>

class Solution_88x {
public:

    //887�Ӽ��������ҵ�f����С������


    //˼·�����k����1�������ö��ֲ��ң����k������1�������ͷ����
    //����1��ֻ��һ��������������¥������1¥��2¥
    //����2�������������ȶ��֣�n=6�������£�3¥���ˣ������1¥��2¥���Ҳ���4¥5¥6¥���Ҳ������1+3���������һ¥���ñ�����������1����Ӧ��Ҫ�����ģ���Ȼû���ó�f=n�������
    //����ļ����ǣ����֣�Ҳ����ȫ�Ƕ��֣�����ó��Ҳ࣬��ô��һ����û�飬����ó���࣬��ô����ʣ�µı���
    //�����1+2���Ҳ������ǣ��Ҳ���Ҳ���
    //���д�ݹ飬��ʵ����������������

    //�м����⣺mid���ĵ����⣬��Ϊ�����±괫�ݣ����Կ��ܻ���һ�㣬���ǽ�������ֱ߽�����Ҳû������ȷ���⣬�ص����������С��


    //��̬�滮��
    //էһ���Ƕ������⣬��ʵҲ����ȫ�ǣ����ֵ�˼ά�ܴ�Ž�����⣬���Ǵﲻ����ĿҪ��ľ�ȷ��ֵ�������õ�������ֵ�Ǹ���̬ƽ��Ĺ���
    //����С����һ����̬�Ĺ��̣�����һ���㶨�ķ�����������������ֻ��һ��������Ͳ��ܶ����ˣ�������������Ҷ�����������̬�Ĳ���
    //����Ҳ�������ֵ�һ����ֵ��n/2�����ɶ����������O(log(n/2))�������������������������ӶȻ���O(n/2)
    //��������Ҳ�Ҳ���Ǳ�׼�Ķ�������������������루��һ���ǵ�һ�㣬���϶�����ײ㣩��Ȼ�Ǳ���
    //ƽ�����
    int superEggDrop(int k, int n);

};