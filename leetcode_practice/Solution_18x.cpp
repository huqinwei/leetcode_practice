#include "Solution_18x.h"





void Solution_18x::rotate(std::vector<int>& nums, int k) {
    if (nums.size() <= 1)
        return;
    //ȫ��ת
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    //��෭ת
    i = 0;
    j = k - 1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    //�Ҳ෭ת
    i = k;
    j = nums.size()-1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    

}

