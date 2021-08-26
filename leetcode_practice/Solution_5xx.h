#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


///所有500-599题

class Solution_5xx {
public:




    //509
    //这个不算DP？或者递归开销大？
    int fib_mine(int n);

    int fib(int n);

    //557. 反转字符串中的单词 III
    string reverseWords(string s);

    //567. 字符串的排列
    //s1是短串，可以任意打乱顺序做成一个变种，问s1是否在s2内（潜台词：统计所有字母的出现频率）
    bool checkInclusion(string s1, string s2);


    //572 另一棵树的子树
    //暴力法，遍历整棵树，每颗子树进行完全匹配，大循环套小循环
    //O(N*M),N是root长，M是subRoot长
    bool isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot);

    //572:KMP法
    bool isSubtree(TreeNode* root, TreeNode* subRoot);

	//589. N 叉树的前序遍历
	vector<int> preorder(Node* root);
	//589. N 叉树的后序遍历
	vector<int> postorder(Node* root);
};


