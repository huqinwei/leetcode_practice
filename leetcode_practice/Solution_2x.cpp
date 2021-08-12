#include "Solution_2x.h"


bool Solution_2x::isValid(std::string s) {
    //简单的堆栈判断，控制栈容器的通道，写一些具体符号的判断
    //给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
    std::vector<char> stack;
    for (int i = 0; i < s.size(); ++i) {
        //std::cout << s[i] << " ";
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.size() == 0)
                return false;
            char tmp = stack.back();
            if (s[i] == ')' && tmp != '(')
                return false;
            if (s[i] == ']' && tmp != '[')
                return false;
            if (s[i] == '}' && tmp != '{')
                return false;
            stack.pop_back();
        }
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack.push_back(s[i]);
        }
    }
    if (stack.size() != 0)
        return false;
    return true;
}

double Solution_2x::newtonSqrt(double n) {
    double x0 = n;
    while (abs(x0*x0 - n) >= 1e-6) {
         x0 = 0.5*(n / x0 + x0);
    }
    return x0;
}


ListNode* Solution_2x::mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode  head;
    ListNode* curr=&head;
    while (l1 && l2) {
        if (l1->val <= l2->val)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        else
        {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    if (l1) {
        curr->next = l1;
    }
    else{/*if (l2)*/ 
        curr->next = l2;
    }
    return head.next;


}


inline void back_tracking(int n, std::vector<std::string> &res,int left,int right,std::string str) {
    if (left < right)//概括所有错误
        return;
    if (left == right && right == n) {//遍历结束
        res.push_back(str);
    }
    if (left < n) {
        back_tracking(n, res, left + 1, right, str + "(");
    }
    if (right < n) {
        back_tracking(n, res, left, right + 1, str + ")");
    }
}
std::vector<std::string> Solution_2x::generateParenthesis(int n) {
    std::vector<std::string> res;
    back_tracking(n,res,0,0,"");
    return res;
}

ListNode* Solution_2x::swapPairs(ListNode* head) {
    if (!head || !head->next)//也是必须的，中间过程不会触发问题，但是起始head==NULL可能发生，因为是||，所以head->next可以并列而不报错
        return head;
    //加各种if判断
    ListNode* next = head->next;
    if (next->next)//没有下一段则不需要递归
        head->next = swapPairs(next->next);//衔接
    else//必须的终止操作，不然head和next死循环？程序不会死，但是链表会死
        head->next = NULL;
    next->next = head;//逆转当前段，（顺序，太早操作会破坏next->next）

    return next;
}
int Solution_2x::removeElement(std::vector<int>& nums, int val) {
    if (nums.size() == 0)
        return 0;
    int index_l = 0;
    int index_r = nums.size() - 1;

    while (index_l < index_r)
    {
        while (index_l<index_r && nums[index_r] == val)//index_r的动态调整
            index_r -= 1;
        while (index_l < index_r && nums[index_l] != val)
            index_l += 1;

        int tmp = nums[index_r];
        nums[index_r] = nums[index_l];
        nums[index_l] = tmp;
    }
    return nums[index_l] == val ? index_l : index_l + 1;
}

//也不是merge，这块想写的是加法来着
/*
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode NewHead;
    ListNode *curNode = NewHead;
    bool carry = false;

    while (l1->next&&l2->next)
    {
        int curr = l1->val + l2->val + carry;
        carry = curr / 10;
        curr = curr % 10;

    }
    if ()
    {
    }
    if ()
    {
    }
}
*/



int sqrt(int x)
{
    // 避免除零错误，单独处理 x = 0 的情况
    if (x == 0)
        return x;
    int t = x / 2 + 1;
    while (t > x / t)
        t = (t + x / t) / 2;
    return t;
}
