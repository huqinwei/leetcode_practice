#include "Solution_18x.h"





void Solution_18x::rotate(std::vector<int>& nums, int k) {
    if (nums.size() <= 1)
        return;
    //È«·­×ª
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    //×ó²à·­×ª
    i = 0;
    j = k - 1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    //ÓÒ²à·­×ª
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

