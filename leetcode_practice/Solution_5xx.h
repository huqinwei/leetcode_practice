#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


///����500-599��

class Solution_57x {
public:



    //572 ��һ����������
    //��������������������ÿ������������ȫƥ�䣬��ѭ����Сѭ��
    //O(N*M),N��root����M��subRoot��
    bool isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot);

    //672:KMP��
    bool isSubtree(TreeNode* root, TreeNode* subRoot);


};



class Solution_50x {
public:



    //509
    //�������DP�����ߵݹ鿪����
    int fib_mine(int n);

    int fib(int n);


};


