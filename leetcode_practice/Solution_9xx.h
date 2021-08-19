#pragma once
#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"
#include <unordered_map>
#include "sort_collections.h"

class Solution_9xx {
public:
    //912
    //见  sort_collections.h



    //977，非递减顺序数组，每个数字平方，还要数组非递减，返回
    //粗暴理解：其实就是遍历平方加排序
    //题目标签：数组、双指针、排序
    //优化思路：主要就是区分正负，按绝对值的顺序去平方：但是先平方再排序和先排序再平方感觉差不多
    //双指针思路：找到绝对值最低点，不一定是0，然后比较双指针，左右分别遍历，平方，插入，复杂度O(n)
    //题设隐含条件：单调递增——，0（最低点）两侧是有序的，O(N)便可完成排序。
    //平方前找中心点和平方后找哪个方便？都一样，总的复杂度O(2N)，空间复杂度O(N)
    //有几个缺点，但是实际提交看运气
    std::vector<int> sortedSquares_mine(std::vector<int>& nums);

    //拿来的一个双指针，速度略快，可能是因为寻找中间点的过程少了O(N/2)，但是他这样判断有没有bug？如果没有0，-2和+1先插入哪个？
    //if (nums[i] * nums[i] < nums[j] * nums[j]) {//这个地方算是消除了-2和+1先插入谁的歧义
    //即便没消除歧义，他只要遍历的时候多一步最后一个负数和第一个正数谁更小就行
    std::vector<int> sortedSquares(std::vector<int>& nums);


    //找中点的方式都绕远了，双指针直接从双边对比插入就足够！！！！




};
