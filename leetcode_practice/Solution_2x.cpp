#include "Solution_2x.h"


bool Solution_2x::isValid(std::string s) {
    //�򵥵Ķ�ջ�жϣ�����ջ������ͨ����дһЩ������ŵ��ж�
    //����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
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
    if (left < right)//�������д���
        return;
    if (left == right && right == n) {//��������
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

//Ҳ����merge�������д���Ǽӷ�����
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
    // ���������󣬵������� x = 0 �����
    if (x == 0)
        return x;
    int t = x / 2 + 1;
    while (t > x / t)
        t = (t + x / t) / 2;
    return t;
}