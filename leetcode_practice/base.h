#pragma once
//Definition for singly-linked list.

#include <algorithm>//std::min��
#include <vector>
#include "math.h"

#include <chrono>
#include <string.h>
#include <string>

//IO
#include <iostream>

//����
#include <vector>
#include <queue>

//�㷨
#include "math.h"
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>


using namespace std;


struct SinglyListNode {
    int val;
	SinglyListNode* next;
	SinglyListNode(int x) : val(x), next(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {//N���������ݽṹ
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};