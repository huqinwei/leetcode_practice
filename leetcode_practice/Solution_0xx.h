#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"

///����0-99��

class Solution_0xx {
public:

    //1.����֮��
    //��ϣ���ֵ䷨�������key��֤����Ҫ���ҵ���
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> twoSum_2points(std::vector<int>& nums, int target);
    std::vector<int> twoSum_brute(std::vector<int>& nums, int target);
    //02:������ӣ�������
    ListNode* addTwoNumbers_iteration(ListNode* l1, ListNode* l2);
    //�ݹ鷨
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);



    //20 ��Ч������
    bool isValid(std::string s);
    ///
    //21:ֱ�ӵ����������ɣ����������ݹ飩
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    //22.��������
    std::vector<std::string> generateParenthesis(int n);

    //24:������������ڵ㣺�ݹ鷨���ܸ�����һ�㣻��������ÿ��������������һָͨ��������ֲ����죬��˳��û�䣻
    ListNode* swapPairs(ListNode* head);


    //26.ɾ�����������е��ظ���
    int removeDuplicates(std::vector<int>& nums);


    //27.�Ƴ�����Ԫ�أ����������������³��ȵ���ֵ�����ģ�˫ָ������������Ե���ֵ
    int removeElement(std::vector<int>& nums, int val);


    //35 ���ֲ��ң���������λ��

    int searchInsert(std::vector<int>& nums, int target);




    //42 ����ˮ
    //����ε��������
    //̰����������ӷ����ٶȽ���
    //����ԭ��ͬһ�����ӣ������Ҳ�ĸ߶����ӣ��ǻ���������ģ�������
    //���Ӷȣ�O(N^2)��Ӧ��Ҳ��O(N^2)�����ǻ��������O(N*K)��k��gap�ĳ���
    int trap_greedy(std::vector<int>& height);

    //˫ָ�룺��ʵ�������ǰ��greedy��˼·��ֻ��֮ǰû����һЩ�ռ�����ʱ�䣬û��˫��ͬʱ����������ʱ��
    //ʱ�临�Ӷȣ�O(n)
    int trap(std::vector<int>& height);

    //�����ӽ�̫�����ˣ���һ��˼·��ÿһ������ֱ��ȥ��������ߣ�������ӵ�������߾ͳ�����,ʵ��������ʵ�������
    //��ʱ�����Ӷ�ΪO(n^2��,���ҵ�trap_greedy������
    int trap_BF(std::vector<int>& height);

    //һ��up��BF������iter��ز���,���ҵ�trap_BFҪ�죬��ͨ��
    int trap_BF2(std::vector<int>& height);

    //42 DP��max_l��max_r�ȵ���������Ȼ��ֱ�Ӳ�ѯ
    //ʱ�临�Ӷ�O(3*n)
    int trap_DP(std::vector<int>& height);


    //69
    double newtonSqrt(double n);


    //70:��¥�ݣ���̬�滮
    //������
    int climbStairs_slide_window(int n);
    //���鷨����Ϊn���ޣ�����һ����Ϊn�������ǿ��Խ��ܵģ�
    int climbStairs(int n);


    //88  �ϲ������������飬����nums1����Ԥ���ռ�\
            ���룺nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3\
        �����[1, 2, 2, 3, 5, 6]
//����˫ָ���˼·������β�壬���ͷ��tmp��Ƚ϶࣬�����������൱������m����������һ��
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);




};
