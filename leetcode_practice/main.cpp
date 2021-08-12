#include "Solution_0x.h"
#include "Solution_2x.h"

#include <vector>
#include <iostream>
int main() {


    /////////////////////////solution20-29 start///////////////////////////////////////////
    Solution_2x sol_2x;

#if 0
    ListNode *p13 = new ListNode(15);
    ListNode *p12 = new ListNode(3, p13);
    ListNode *p11 = new ListNode(1, p12);
    ListNode *p23 = new ListNode(7);
    ListNode *p22 = new ListNode(4, p23);
    ListNode *p21 = new ListNode(2, p22);
    ListNode* merged_list = sol_2x.mergeTwoLists(p11,p21);
#endif

    std::vector<std::string> res22;
    res22 = sol_2x.generateParenthesis(2);
    return 0;

    double ret6x = sol_2x.newtonSqrt(88);

    bool ret2x = sol_2x.isValid("()[]{}");
    return 0;

    std::vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    Solution_0x sol_1;
    std::vector<int> res;
    res = sol_1.twoSum(nums,target);
    return 0;


    /////////////////////////solution20-29 end///////////////////////////////////////////
    Solution_0x sol;
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










