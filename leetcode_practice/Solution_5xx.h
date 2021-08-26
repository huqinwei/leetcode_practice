#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


///����500-599��

class Solution_5xx {
public:




    //509
    //�������DP�����ߵݹ鿪����
    int fib_mine(int n);

    int fib(int n);

    //557. ��ת�ַ����еĵ��� III
    string reverseWords(string s);

    //567. �ַ���������
    //s1�Ƕ̴��������������˳������һ�����֣���s1�Ƿ���s2�ڣ�Ǳ̨�ʣ�ͳ��������ĸ�ĳ���Ƶ�ʣ�
    bool checkInclusion(string s1, string s2);


    //572 ��һ����������
    //��������������������ÿ������������ȫƥ�䣬��ѭ����Сѭ��
    //O(N*M),N��root����M��subRoot��
    bool isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot);

    //572:KMP��
    bool isSubtree(TreeNode* root, TreeNode* subRoot);

	//589. N ������ǰ�����
	vector<int> preorder(Node* root);
	//589. N �����ĺ������
	vector<int> postorder(Node* root);
};


