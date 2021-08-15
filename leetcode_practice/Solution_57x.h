#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


class Solution_57x {
public:



    //572 另一棵树的子树
    //暴力法，遍历整棵树，每颗子树进行完全匹配，大循环套小循环
    //O(N*M),N是root长，M是subRoot长
    bool isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot);

    //672:KMP法
    bool isSubtree(TreeNode* root, TreeNode* subRoot);


};

