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
            tail = curr;//������ʱ��̫�̣���ά��tailҲ��
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        //���Ҫ���ٶȣ�����ֱ������������β��������
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
        //index -= 1;//prev��-1��Ϊ���
		SinglyListNode* prev = head;
		while (index > 0 && prev) {//��Ҫ��while(index--)�����׳�bug���������������ʹ��index���ڶ�����̽Ҳ����ֵ
            prev = prev->next;
            index--;
		}
        if (index>-1) {//�����Ǹպñ�����
			SinglyListNode* node = new SinglyListNode(val);
			node->next = prev->next;//˳��
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
		while (index > 0 && prev) {//��Ҫ��while(index--)�����׳�bug���������������ʹ��index���ڶ�����̽Ҳ����ֵ
			prev = prev->next;
			index--;
		}

        if(prev&&prev->next){
            SinglyListNode* to_delete = prev->next;
            if (to_delete == tail) {
                tail = prev;//��ôtail���벻�ܱ�delete�ƻ�
            }
            prev->next = prev->next->next;
        }
		return;
    }

private:
	SinglyListNode* head = NULL;
	SinglyListNode* tail = NULL;
};

///����700-799��

class Solution_7xx {
public:
    //704 ���ֲ���
    int search(std::vector<int>& nums, int target);

    //733. ͼ����Ⱦ
    //����һ���ҵ�������⣬����һ���޸�
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor);

	//���壺�Ƿ�Ŀ��ɫҲ��������ɫ��Χ����Ȼ�����øı䣬����Ӱ����ͨ�����磬��1��ɫ2,�����ݼ���1,0,1����1��2,1������Ƿ�һ�£�
    //���걸�߼������ϣ��²��Ƿ��������Ͽ�������
    ////ʵ�⣬���ݼ����ִ�newColor==��color������ȡ��
	vector<vector<int>> floodFill_trick(vector<vector<int>>& image, int sr, int sc, int newColor);

    //746 ��С������¥��
    int minCostClimbingStairs(std::vector<int>& cost);



    //796 ��ת�ַ������ж������ַ����Ƿ�Ϊ��ת�ַ���
    //KMP�㷨��Knuth-Morris-Pratt�ַ��������㷨
    bool rotateString(std::string s, std::string goal);
};

