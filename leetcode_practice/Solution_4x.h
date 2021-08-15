#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


class Solution_4x {
public:



    //42 ����ˮ
    //����ε��������
    //̰����������ӷ����ٶȽ���
    //����ԭ��ͬһ�����ӣ������Ҳ�ĸ߶����ӣ��ǻ���������ģ�������
    //���Ӷȣ�O(N^2)��Ӧ��Ҳ��O(N^2)�����ǻ��������O(N*K)��k��gap�ĳ���
    int trap_greedy(std::vector<int>& height);
    //˫ָ�룺��ʵ�������ǰ��greedy��˼·��ֻ��û����һЩ�ռ�����ʱ�䣬û��˫��ͬʱ����������ʱ��
    //ʱ�临�Ӷȣ�O(n)
    int trap(std::vector<int>& height);

    //�����ӽ�̫�����ˣ���һ��˼·��ÿһ������ֱ��ȥ��������ߣ�������ӵ�������߾ͳ�����,ʵ��������ʵ�������
    //��ʱ�����Ӷ�ΪO(n^2��,���ҵ�̰��������
    int trap_BF(std::vector<int>& height);

    //һ��up��BF������iter��ز���,���ҵ�BFҪ�죬��ͨ��
    int trap_BF2(std::vector<int>& height);

    //42 DP��max_l��max_r�ȵ���������Ȼ��ֱ�Ӳ�ѯ
    //ʱ�临�Ӷ�O(3*n)
    int trap_DP(std::vector<int>& height);


};

