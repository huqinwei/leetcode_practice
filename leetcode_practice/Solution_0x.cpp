
#include "solution_0x.h"

std::vector<int> Solution_0x::twoSum(std::vector<int>& nums, int target) {
    std::vector<int> two_index;
    //ʹ�ù�ϣ�����
    std::map<int, int> dictionary;
    for (int i = 0; i < nums.size(); ++i) {
        int find_key = target - nums[i];
        if (dictionary.count(find_key)>0) {//dictionary[cur] != 0 �±���0��������������ж�  &&  dictionary[cur]�Զ����ʲ�д��k-v
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
    //������
    //���˱߽����֮��ģ�û����������
    //��ǰ����92.34%

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
    //����˫ָ�뷨
    //����ָ��ͬʱ���м��ƶ���������
    //�뱩����ͬʱ�ύ������

    //��Ҫ�������򣬲���֤����,�����Ժ󣬷��ص�index�����ˣ��������˫ָ��Ҫ�ض��������飬�Լ�sort��Ҫ�Լ���ס��Ӧ��ϵ��

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


ListNode* Solution_0x::addTwoNumbers_iteration(ListNode* l1, ListNode* l2) {
    ListNode*ret = new ListNode();
    ListNode*cur = ret;
    bool carry = 0;
    while (l1 != NULL || l2 != NULL || carry) {
        int tmp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;//���ȼ������⣬��������
        carry = tmp >= 10 ? 1 : 0;
        cur->val = tmp % 10;
        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
        if (!carry && !l1 && !l2)
            return ret;
        cur->next = new ListNode();
        cur = cur->next;

    }
    return ret;
}

//����һ��������carry���ӵ�l1����l2��
inline ListNode* add_two_numbers(ListNode* l1, ListNode* l2, bool carry) {
    ListNode *curr = new ListNode;
    if (l1) {
        curr->val += l1->val;
        l1 = l1->next;
    }
    if (l2) {
        curr->val += l2->val;
        l2 = l2->next;
    }
    curr->val += carry;
    carry = curr->val / 10;
    curr->val %= 10;

    if (l1||l2||carry) {
        curr->next = add_two_numbers(l1, l2, carry);
    }

    return curr;
}


ListNode* Solution_0x::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode ret;
    ret.next = add_two_numbers(l1, l2, 0);
    return ret.next;
}







