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



};

