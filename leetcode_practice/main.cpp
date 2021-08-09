#include "problem_1_10.h"
#include <vector>
#include <iostream>
int main() {
    Solution sol;


    /*
    *µÚÒ»Ìâ
    std::vector<int> nums;
    std::vector<int> res;

    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(4);
    int target = 6;

    res = sol.twoSum(nums, target);
    std::cout << res[0] << "," << res[1] << std::endl;
    */

    ListNode l11(2), l12(4), l13(3),
        l21(5), l22(6), l23(4);
    l11.next = &l12;
    l12.next = &l13;
    l21.next = &l22;
    l22.next = &l23;



    ListNode *ret = sol.addTwoNumbers(&l11, &l21);


//     ListNode l3(9),
//         l41(1), l42(9), l43(9), l44(9), l45(9), l46(9), l47(9), l48(9), l49(9), l410(9);
//     l41.next = &l42;
// 
//     ListNode *ret = sol.addTwoNumbers(&l3, &l41);


    return 0;

}










