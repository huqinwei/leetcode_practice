#include "Solution_16x.h"


int Solution_16x::majorityElement_by_sort(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}
int Solution_16x::majorityElement(std::vector<int>& nums) {
    int winner_count = 0;
    int winner_value = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (winner_count == 0){
            winner_value = nums[i];
            winner_count++;
        }
        else if (winner_value == nums[i]){
            winner_count++;
        }
        else if (winner_value != nums[i]){
            winner_count--;
        }
    }
    return winner_value;
}