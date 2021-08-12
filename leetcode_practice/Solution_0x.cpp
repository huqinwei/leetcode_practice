
#include "solution_0x.h"

std::vector<int> Solution_0x::twoSum(std::vector<int>& nums, int target) {
    std::vector<int> two_index;
    //使用哈希表查找
    std::map<int, int> dictionary;
    for (int i = 0; i < nums.size(); ++i) {
        int find_key = target - nums[i];
        if (dictionary.count(find_key)>0) {//dictionary[cur] != 0 下标有0，不可以用这个判断  &&  dictionary[cur]自动访问并写入k-v
            two_index.push_back(dictionary[find_key]);
            two_index.push_back(i);
            return two_index;
        }
        dictionary[nums[i]] = i;
    }
    return two_index;
}

std::vector<int> Solution_0x::twoSum_brute(std::vector<int>& nums, int target) {
    std::vector<int> two_index;
    //暴力法
    //除了边界访问之类的，没有其他问题
    //当前击败92.34%

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                two_index.push_back(i);
                two_index.push_back(j);
                return two_index;
            }

        }
    }
    return two_index;
}

#include "Solution_0x.h"




std::vector<int> Solution_0x::twoSum_2points(std::vector<int>& nums, int target) {

    std::vector<int> two_index;
    return two_index;
#if 0
    //左右双指针法
    //左右指针同时向中间移动，遇到数
    //与暴力法同时提交，击败

    //需要主动排序，不保证升序,排序以后，返回的index不对了，所以这个双指针要特定有序数组，自己sort还要自己记住对应关系。

    std::sort(nums.begin(), nums.end());

    std::vector<int> two_index;
    int sum = 0;
    int i = 0, j = nums.size() - 1;
    sum = nums[i] + nums[j];
    while (sum != target) {
        if (sum < target) {
            if (nums[i + 1] + nums[j] > target)
                j--;
            else
                i++;
        }
        else {

            if (nums[i] + nums[j - 1] < target)
                i++;
            else
                j--;
            ;
        }
        sum = nums[i] + nums[j];
    }
    two_index.push_back(i);
    two_index.push_back(j);
    return two_index;
#endif
}


ListNode* Solution_0x::addTwoNumbers(ListNode* l1, ListNode* l2) {


    /*
    *做错了，因为逆序的缘故，其实头结点是最后一位，简单迭代就好，瓶颈是存储位数，以前做过，这次没读好题（或者写的难懂）
    unsigned long long num1 = 0,num2=0,sum=0;
    //输入是逆序的
    //节点2  4  3对应数字342
    int i = 0,j=0;
    while (l1 != NULL) {
    num1 += l1->val * pow(10,i++);
    l1 = l1->next;
    }
    while (l2 != NULL) {
    num2 += l2->val * pow(10,j++);
    l2 = l2->next;
    }
    sum = num1 + num2;

    ListNode*ret = new ListNode();
    ListNode*cur = ret;
    while (sum) {
    cur->val = sum%10;
    sum /= 10;
    if (!sum) {
    return ret;
    }
    ListNode*tmp = new ListNode();
    cur->next = tmp;
    cur = tmp;

    }

    return ret;
    */
    return NULL;
}







