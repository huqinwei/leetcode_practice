#include "Solution_12x.h"



int Solution_12x::maxProfit_II(std::vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i < prices.size()-1; ++i) {
        if (prices[i] > prices[i + 1])
            continue;
        profit += prices[i + 1] - prices[i];
    }
    return profit;
}


void Solution_12x::rotate(std::vector<int>& nums, int k) {
    if (nums.size() <= 1)
        return;
    k = k%nums.size();
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