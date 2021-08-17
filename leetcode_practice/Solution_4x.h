#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


class Solution_4x {
public:



    //42 接雨水
    //网传蔚来笔试题
    //贪婪：暴力填坑法？速度较慢
    //变慢原因，同一个格子，随着右侧的高度增加，是会多次逐层填充的，有冗余
    //复杂度：O(N^2)，应该也是O(N^2)，但是会更趋近于O(N*K)，k是gap的长度
    int trap_greedy(std::vector<int>& height);

    //双指针：其实这就是我前边greedy的思路，只是之前没有用一些空间来换时间，没有双向同时操作，输了时间
    //时间复杂度：O(n)
    int trap(std::vector<int>& height);

    //可能视角太局限了，另一个思路是每一个格子直接去找左右最高，这个格子的理论最高就出来了,实现起来其实代码更简单
    //超时：复杂度为O(n^2）,比我的trap_greedy还慢！
    int trap_BF(std::vector<int>& height);

    //一个up的BF，用了iter相关操作,比我的trap_BF要快，能通过
    int trap_BF2(std::vector<int>& height);

    //42 DP：max_l和max_r先迭代出来，然后直接查询
    //时间复杂度O(3*n)
    int trap_DP(std::vector<int>& height);


};

