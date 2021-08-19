#pragma once

#include <string.h>
#include "base.h"
#include <vector>
#include <iostream>


#include <unordered_set>


///����200-299��

class Solution_2xx {
public:
    //200  ��������//ֻ�к���ֱ������
    //��ֱ�۵ľ���DFS����һ��mask�����������������±꣬��Ȼ��ֻ��ֵΪ1�Ĳ����룬ÿһ�㶼�ѵ�ǰ��maskͿ�ڣ�Ȼ��ǰ�����ҵݹ����
    
    //û��ɾ��ԭʼ��Ϣ����������ʱ��Ϳռ�
    int numIslands_DFS_mask(std::vector<std::vector<char>>& grid);
    //DFS inplace��
    int numIslands_inplace(std::vector<std::vector<char>>& grid);

    //BFS  BFS�ر�queue
    int numIslands_BFS(std::vector<std::vector<char>>& grid);

    //union find
    //���鼯


    //206  ��ת����
    //�ݹ鷨

    ListNode* reverseList(ListNode* head);




    //217�������ظ�Ԫ�أ���map����set����
    //����λ����֮���ȡ�ɽⷨ��������Ϊû������ǰ��������Ӧ�ð첻����
    bool containsDuplicate(std::vector<int>& nums);


    //240
    //����ε��������
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);


    Solution_2xx() :m_bad_version(0) {}
    Solution_2xx(int bad_version) :m_bad_version(bad_version) {}
    int m_bad_version = 4;
    //278 ���ֲ���
    bool isBadVersion(int version) { return version >= m_bad_version; }
    int firstBadVersion(int n);
    long long badversion_recursion(long long start, long long end);



};
