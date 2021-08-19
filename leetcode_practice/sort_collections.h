#pragma once

#include "base.h"

class SortCollections {
public:
    //���Բο� https://leetcode-cn.com/problems/sort-an-array/solution/dong-hua-mo-ni-yi-ge-kuai-su-pai-xu-wo-x-7n7g/
    //���˽��ⲻͬ���򣬺���Ƶ��ʾ�����п���������Ż�˼·


    //��������
    void Quicksort(int array[], int L, int R);

    //�������򳣹�棬ƿ��������1,2,3,4,5,6,.....,49999,50000��ʱ��������pivot����ȡ��࣬ÿ�����һ�鷢�ֲ����ţ�������ȴ��������
    //���ⲻ�ڱ��������������ڣ������pivot��Ϊ�ָ��ȥ�����֣��ᵼ�����һֱΪ�գ��Ҳ�һֱ������Ϊ�ݹ���ڴ濪�����⣬���ܻ�����д����ͨ����
    void Quicksort_regular(std::vector<int>& nums, int L, int R);

    //�����Ż���
    void Quicksort(std::vector<int>& nums, int L, int R);

    //912����������
    std::vector<int> sortArray_call_Quicksort(std::vector<int>& nums);
    std::vector<int> sortArray(std::vector<int>& nums);
    
};



