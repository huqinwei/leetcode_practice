#include "Solution_21x.h"





bool Solution_21x::containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> sets;
    for (int i = 0; i < nums.size(); ++i) {
        if (sets.find(nums[i])!=sets.end())
            return true;
        sets.insert(nums[i]);
    }

    return false;
}