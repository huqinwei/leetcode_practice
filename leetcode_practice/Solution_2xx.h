#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


///所有200-299题

class Solution_2xx {
public:
    //200  岛屿数量//只有横纵直连才算
    //最直观的就是DFS，搞一个mask，外层遍历矩阵所有下标，当然，只有值为1的才陷入，每一层都把当前的mask涂黑，然后前后左右递归访问
    
    //没有删除原始信息，但牺牲了时间和空间
    int numIslands_DFS_mask(std::vector<std::vector<char>>& grid);
    //DFS inplace版
    int numIslands_inplace(std::vector<std::vector<char>>& grid);

    //BFS  BFS必备queue
    int numIslands_BFS(std::vector<std::vector<char>>& grid);

    //union find
    //并查集


    //206  反转链表
    //递归法

    ListNode* reverseList(ListNode* head);


    //213 打家劫舍 II rob II
    //这题需要明确dp[i-1]代表什么，dp能包含什么信息量，损失什么信息量
    //如果想用错位数组，下标的统一需要费功夫
    //优化思路：两个数组，却不应该用两次循环，时间效率从O(n)变成了O(2n)，尤其我的下标统一，我有预处理，直接合并两次循环就好
    int rob_II(vector<int>& nums);

    //217，存在重复元素：用map或者set查重
    //关于位运算之类的取巧解法，这里因为没有特殊前置条件，应该办不到。
    bool containsDuplicate(std::vector<int>& nums);


    //240
    //网传蔚来笔试题
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);


    Solution_2xx() :m_bad_version(0) {}
    Solution_2xx(int bad_version) :m_bad_version(bad_version) {}
    int m_bad_version = 4;
    //278 二分查找
    bool isBadVersion(int version) { return version >= m_bad_version; }
    int firstBadVersion(int n);
    long long badversion_recursion(long long start, long long end);


    //283 移动零： 双指针
    //错误解法：双指针相对运动，并且swap，甚至对前半部分结果rotate！！！！因为swap的过程是见缝插数，顺序混乱，回不来了。
    //最聪明的做法应该是记住0（也不用，总长一定），双指针向前移动，当前需要跳过几个0双指针完成，最后0统一插在后边
    void moveZeroes(std::vector<int>& nums);

};

