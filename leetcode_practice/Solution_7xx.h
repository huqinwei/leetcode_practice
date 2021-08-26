#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>
class MyLinkedList {//707
	struct SinglyListNode {
		int val;
		SinglyListNode* next;
		SinglyListNode(int x) : val(x), next(NULL) {}
	};
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        tail = head = new SinglyListNode(0);
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        SinglyListNode* curr = head;
        while (index-->-1&&curr) {
            curr = curr->next;
        }
        if (curr)
            return curr->val;
        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode* next = head->next;
        SinglyListNode* curr = new SinglyListNode(val);
        head->next = curr;
        curr->next = next;
        if (!next)
            tail = curr;//不过这时候太短，不维护tail也行
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        //如果要求速度，可以直接来个迭代的尾巴来提速
		SinglyListNode* prev = head;
#if 0
		while (prev->next) {
			prev = prev->next;
		}
#endif
        prev = tail;
		SinglyListNode* curr = new SinglyListNode(val);
        prev->next = curr;
        tail = curr;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        //index -= 1;//prev以-1作为起点
		SinglyListNode* prev = head;
		while (index > 0 && prev) {//不要用while(index--)，容易出bug，尤其是你想后续使用index，第二次试探也减了值
            prev = prev->next;
            index--;
		}
        if (index>-1) {//极限是刚好遍历完
			SinglyListNode* node = new SinglyListNode(val);
			node->next = prev->next;//顺序
            prev->next = node;
            if (!node->next)
                tail = node;
        }
        else {
            return;
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
		SinglyListNode* prev = head;
		while (index > 0 && prev) {//不要用while(index--)，容易出bug，尤其是你想后续使用index，第二次试探也减了值
			prev = prev->next;
			index--;
		}

        if(prev&&prev->next){
            SinglyListNode* to_delete = prev->next;
            if (to_delete == tail) {
                tail = prev;//那么tail必须不能被delete破坏
            }
            prev->next = prev->next->next;
        }
		return;
    }

private:
	SinglyListNode* head = NULL;
	SinglyListNode* tail = NULL;
};

///所有700-799题

class Solution_7xx {
public:
    //704 二分查找
    int search(std::vector<int>& nums, int target);

    //733. 图像渲染
    //就是一个找岛屿的问题，附加一个修改
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);

	//歧义：是否目标色也算重新上色范围？虽然他不用改变，但是影响联通，例如，给1上色2,，数据集是1,0,1还是1，2,1，结果是否一致？
    //在完备逻辑基础上，猜测是否条件不严苛，提速
    ////实测，数据集出现从newColor==旧color，不能取巧
	vector<vector<int>> floodFill_trick(vector<vector<int>>& image, int sr, int sc, int newColor);

    //746 最小花费爬楼梯
    int minCostClimbingStairs(std::vector<int>& cost);



    //796 旋转字符串，判断两个字符串是否互为旋转字符串
    //KMP算法：Knuth-Morris-Pratt字符串查找算法
    bool rotateString(std::string s, std::string goal);
};

