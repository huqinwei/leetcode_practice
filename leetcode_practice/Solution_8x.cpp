#include "Solution_8x.h"



void Solution_8x::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int insert_index = m + n - 1;
    int p1 = m - 1;
    int p2 = n - 1;

    while (p1>=0&&p2>=0&&insert_index>=0){
        if(nums1[p1]>nums2[p2])
            nums1[insert_index--] = nums1[p1--];
        else
            nums1[insert_index--] = nums2[p2--];
    }
    //还剩一个数组没有遍历完:nums1无需操作
    while (p2>=0)
        nums1[insert_index--] = nums2[p2--];

}

