#include "Solution_0x.h"
#include "Solution_2x.h"
#include "Solution_4x.h"
#include "Solution_8x.h"
#include "Solution_12x.h"
#include "Solution_13x.h"
#include "Solution_16x.h"
#include "Solution_18x.h"

#include "Solution_21x.h"
#include "Solution_24x.h"



#include <vector>
#include <iostream>


int main() {




    /////////////////////////solution20-29 start///////////////////////////////////////////
    Solution_2x sol_2x;
    Solution_0x sol_0x;
    Solution_4x sol_4x;
    Solution_8x sol_8x;
    Solution_13x sol_13x;
    Solution_16x sol_16x;
    Solution_18x sol_18x;
    Solution_21x sol_21x;
    Solution_24x sol_24x;
    Solution_12x sol_12x;

    std::vector<int> nums_trap({ 0,1,0,2,1,0,1,3,2,1,2,1});
    int ret42=sol_4x.trap(nums_trap);


    std::vector<int> nums_maj({ 3,2,3 });
    sol_16x.majorityElement(nums_maj);
    return 0;


    //std::vector<int> nums({ 7, 1, 5, 3, 6, 4 });
    //sol_12x.maxProfit_II(nums);
    //sol_18x.rotate(nums, 1);

    std::vector<int> nums({ 1,2,3,1 });
    sol_21x.containsDuplicate(nums);


    //std::vector<int> nums({ 1,1,2 });

//     std::vector<int> nums1({ 1,2,3,0,0,0 });
//     std::vector<int> nums2({ 2,5,6 });
//     sol_8x.merge(nums1, 3, nums2, 3);


    std::vector<int> nums1({ 0 });
    std::vector<int> nums2({ 1 });

    sol_8x.merge(nums1, 0, nums2, 1);


    sol_2x.removeDuplicates(nums);

    //int res887 = sol_8x.superEggDrop(2, 9);
    return 0;


#if 0 
    std::vector<std::vector<int>> matrix_nums;
    matrix_nums.push_back(std::vector<int>({ 1, 4, 7, 11, 15 }));
    matrix_nums.push_back(std::vector<int>({ 2, 5, 8, 12, 19 }));
    matrix_nums.push_back(std::vector<int>({ 3, 6, 9, 16, 22 }));
    matrix_nums.push_back(std::vector<int>({ 10, 13, 14, 17, 24 }));
    matrix_nums.push_back(std::vector<int>({ 18, 21, 23, 26, 30 }));


    bool found = sol_24x.searchMatrix(matrix_nums, 5);
    return 0;
#endif

    

//     sol_13x.singleNumber(nums);
//     sol_13x.singleNumber_by_map(nums);


    


    ListNode *p13 = new ListNode(3);
    ListNode *p12 = new ListNode(4, p13);
    ListNode *p11 = new ListNode(2, p12);
    ListNode *p10 = new ListNode(2, p11);
    ListNode *p23 = new ListNode(4);
    ListNode *p22 = new ListNode(6, p23);
    ListNode *p21 = new ListNode(5, p22);
    //ListNode* merged_list = sol_2x.mergeTwoLists(p11,p21);
    //ListNode* ret24 = sol_2x.swapPairs(p10);
    //std::vector<int> nums({ 0, 1, 2, 2, 3, 0, 4, 2 });
#if 0
    std::vector<int> nums({1 });
    sol_2x.removeElement(nums,1);
#endif

    sol_0x.addTwoNumbers(p11, p21);



    std::vector<std::string> res22;
    res22 = sol_2x.generateParenthesis(2);
    return 0;

    double ret6x = sol_2x.newtonSqrt(88);

    bool ret2x = sol_2x.isValid("()[]{}");
    return 0;

    std::vector<int> nums22 = { 2, 7, 11, 15 };
    int target = 9;

    Solution_0x sol_1;
    std::vector<int> res;
    res = sol_1.twoSum(nums22,target);
    return 0;


    /////////////////////////solution20-29 end///////////////////////////////////////////




    ////////////////////////////////////solution0-9 start///////////////////////////////////////////
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

////////////////////////////////////solution0-9 end///////////////////////////////////////////

    return 0;

}










