#include "Solution_7xx.h"


inline int search_recursion(std::vector<int>& nums,int start,int end, int target) {
    int n = end-start+1;
    if (n <= 0)
        return -1;
    int mid = (start+end) / 2;

    if (target == nums[mid])
        return mid;
    else if (target < nums[mid])
        return search_recursion(nums, start, mid - 1, target);
    else
        return search_recursion(nums, mid + 1, end, target);
}

int Solution_7xx::search(std::vector<int>& nums, int target) {
    int n = nums.size();
    return search_recursion(nums, 0, n-1,target);

}
bool Solution_7xx::rotateString(std::string s, std::string goal) {

    return false;
}