#include "Solution_13x.h"



int Solution_13x::singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
        result ^= nums[i];
    return result;
}


int Solution_13x::singleNumber_by_map(std::vector<int>& nums) {
    //���������ȷʵ���Ǻ��ʺ����ֵ䣺��Ϊ�в�����̣�����������˫�ķ��أ��������䵥�ķ��أ���ζ����Ҫ�������������������󣿻���Ҫ����һ���ֵ����ҵ�valueΪ1��
    int result = 0;
    std::unordered_map<int,int> dict;
    for (int i = 0; i < nums.size(); i++) {
        dict[nums[i]] += 1;
    }

    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        if (iter->second == 1)
            return iter->first;
    }
}