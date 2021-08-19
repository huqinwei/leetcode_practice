#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


///所有500-599题

class Solution_57x {
public:



    //572 另一棵树的子树
    //暴力法，遍历整棵树，每颗子树进行完全匹配，大循环套小循环
    //O(N*M),N是root长，M是subRoot长
    bool isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot);

    //672:KMP法
    bool isSubtree(TreeNode* root, TreeNode* subRoot);


};



class Solution_50x {
public:



    //509
    //这个不算DP？或者递归开销大？
    int fib_mine(int n);

    int fib(int n);


};


