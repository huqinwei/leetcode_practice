#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"

///所有0-99题

class Solution_0xx {
public:

    //1.两数之和
    //哈希表字典法：如果有key就证明有要查找的数
    std::vector<int> twoSum(std::vector<int>& nums, int target);
    std::vector<int> twoSum_2points(std::vector<int>& nums, int target);
    std::vector<int> twoSum_brute(std::vector<int>& nums, int target);
    //02:两数相加：迭代法
    ListNode* addTwoNumbers_iteration(ListNode* l1, ListNode* l2);
    //递归法
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);



    //20 有效的括号
    bool isValid(std::string s);
    ///
    //21:直接迭代遍历即可（方法二：递归）
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);

    //22.生成括号
    std::vector<std::string> generateParenthesis(int n);

    //24:两两交换链表节点：递归法可能更清晰一点；迭代法：每次跳两个，来回一通指针操作，局部改造，大顺序没变；
    ListNode* swapPairs(ListNode* head);


    //26.删除排序数组中的重复项
    int removeDuplicates(std::vector<int>& nums);


    //27.移除数组元素，隐含条件：超出新长度的数值不关心，双指针相向遍历，对调数值
    int removeElement(std::vector<int>& nums, int val);


    //35 二分查找，搜索插入位置

    int searchInsert(std::vector<int>& nums, int target);




    //42 接雨水
    //网传蔚来笔试题
    //贪婪：暴力填坑法？速度较慢
    //变慢原因，同一个格子，随着右侧的高度增加，是会多次逐层填充的，有冗余
    //复杂度：O(N^2)，应该也是O(N^2)，但是会更趋近于O(N*K)，k是gap的长度
    int trap_greedy(std::vector<int>& height);

    //双指针：其实这就是我前边greedy的思路，只是之前没有用一些空间来换时间，没有双向同时操作，输了时间
    //时间复杂度：O(n)
    int trap(std::vector<int>& height);

    //可能视角太局限了，另一个思路是每一个格子直接去找左右最高，这个格子的理论最高就出来了,实现起来其实代码更简单
    //超时：复杂度为O(n^2）,比我的trap_greedy还慢！
    int trap_BF(std::vector<int>& height);

    //一个up的BF，用了iter相关操作,比我的trap_BF要快，能通过
    int trap_BF2(std::vector<int>& height);

    //42 DP：max_l和max_r先迭代出来，然后直接查询
    //时间复杂度O(3*n)
    int trap_DP(std::vector<int>& height);


    //69
    double newtonSqrt(double n);


    //70:爬楼梯：动态规划
    //滑窗法
    int climbStairs_slide_window(int n);
    //数组法（因为n有限，设立一个长为n的数组是可以接受的）
    int climbStairs(int n);


    //88  合并两个有序数组，放在nums1，有预留空间\
            输入：nums1 = [1, 2, 3, 0, 0, 0], m = 3, nums2 = [2, 5, 6], n = 3\
        输出：[1, 2, 2, 3, 5, 6]
//类似双指针的思路，可以尾插，如果头插tmp会比较多，最多情况还是相当于整个m都单独存了一份
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);




};
