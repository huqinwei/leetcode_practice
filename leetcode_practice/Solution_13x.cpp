#include "Solution_13x.h"



int Solution_13x::singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
        result ^= nums[i];
    return result;
}


int Solution_13x::singleNumber_by_map(std::vector<int>& nums) {
    //不过这个题确实不是很适合用字典：因为有插入过程，不是碰到成双的返回，是碰到落单的返回，意味着需要遍历结束，遍历结束后？还需要遍历一下字典来找到value为1的
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