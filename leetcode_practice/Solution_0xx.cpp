



#include "Solution_0xx.h"


std::vector<int> Solution_0xx::twoSum(std::vector<int>& nums, int target) {
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

std::vector<int> Solution_0xx::twoSum_brute(std::vector<int>& nums, int target) {
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





std::vector<int> Solution_0xx::twoSum_2points(std::vector<int>& nums, int target) {

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


ListNode* Solution_0xx::addTwoNumbers_iteration(ListNode* l1, ListNode* l2) {
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


ListNode* Solution_0xx::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode ret;
    ret.next = add_two_numbers(l1, l2, 0);
    return ret.next;
}





bool Solution_0xx::isValid(std::string s) {
    //�򵥵Ķ�ջ�жϣ�����ջ������ͨ����дһЩ������ŵ��ж�
    //����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��
    std::vector<char> stack;
    for (int i = 0; i < s.size(); ++i) {
        //std::cout << s[i] << " ";
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.size() == 0)
                return false;
            char tmp = stack.back();//��ʵ��pop����Ҳû����ģ����ֽ�֣�һ����return false��һ����pop
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


ListNode* Solution_0xx::mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode  head;
    ListNode* curr = &head;
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
    else {/*if (l2)*/
        curr->next = l2;
    }
    return head.next;


}


inline void back_tracking(int n, std::vector<std::string> &res, int left, int right, std::string str) {
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
std::vector<std::string> Solution_0xx::generateParenthesis(int n) {
    std::vector<std::string> res;
    back_tracking(n, res, 0, 0, "");
    return res;
}

ListNode* Solution_0xx::swapPairs(ListNode* head) {
    if (!head || !head->next)//Ҳ�Ǳ���ģ��м���̲��ᴥ�����⣬������ʼhead==NULL���ܷ�������Ϊ��||������head->next���Բ��ж�������
        return head;
    //�Ӹ���if�ж�
    ListNode* next = head->next;
    if (next->next)//û����һ������Ҫ�ݹ�
        head->next = swapPairs(next->next);//�ν�
    else//�������ֹ��������Ȼhead��next��ѭ�������򲻻����������������
        head->next = NULL;
    next->next = head;//��ת��ǰ�Σ���˳��̫��������ƻ�next->next��

    return next;
}

int Solution_0xx::removeDuplicates(std::vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
        if (nums[slow] == nums[fast])
            fast++;
        else
            nums[++slow] = nums[fast];
    }
    return slow + 1;
}


int Solution_0xx::removeElement(std::vector<int>& nums, int val) {
    if (nums.size() == 0)
        return 0;
    int index_l = 0;
    int index_r = nums.size() - 1;

    while (index_l < index_r)
    {
        while (index_l<index_r && nums[index_r] == val)//index_r�Ķ�̬����
            index_r -= 1;
        while (index_l < index_r && nums[index_l] != val)
            index_l += 1;

        int tmp = nums[index_r];
        nums[index_r] = nums[index_l];
        nums[index_l] = tmp;
    }
    return nums[index_l] == val ? index_l : index_l + 1;
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



inline int searchInsert_recursion_old(std::vector<int>& nums, int start, int end, int target) {
    if (end < start)//���ڲ��룬����������Ҫע�⣬��Ϊ�ҵ�ʵ��mid-1������mid��С��start�����ǲ����Ӧ����start�������߼���ͨ�����ң������Ż���
        return start;
    if (end == start) {//Ѱ�ҵ���󣬿��ǲ�������
        if (target <= nums[start])
            return start;
        else
            return start + 1;
    }

    int mid = (start + end) / 2;

    if (target == nums[mid])
        return mid;
    else if (target < nums[mid])
        return searchInsert_recursion_old(nums, start, mid - 1, target);
    else
        return searchInsert_recursion_old(nums, mid + 1, end, target);
}

//��Ϊ����/������mid���β���-1Ҳ��������߼�����ֹ������start==end
//����������start=0,mid=1,
//��һ�εݹ鴫��0,1
//mid��0������һ��ѭ����������±�0���Ҳ����±�1��������end==start����ֹ����
//������ֹ������ֻʣһ����������Ҫ�жϣ��ǲ��뵱ǰλ�û�����һ��λ��
inline int searchInsert_recursion(std::vector<int>& nums, int start, int end, int target) {
    if (end == start) {//Ѱ�ҵ���󣬿��ǲ�������
        if (target <= nums[start])
            return start;
        else
            return start + 1;
    }

    int mid = (start + end) / 2;

    if (target == nums[mid])
        return mid;
    else if (target < nums[mid])
        return searchInsert_recursion(nums, start, mid, target);
    else
        return searchInsert_recursion(nums, mid + 1, end, target);
}




int Solution_0xx::searchInsert(std::vector<int>& nums, int target) {
    int n = nums.size();
    return searchInsert_recursion(nums, 0, n - 1, target);
}





//����ˮͰ������м�Ĺ���������gap
int Solution_0xx::trap_greedy(std::vector<int>& height) {
    if (height.size() < 2)//����2�������ܽ�ˮ
        return 0;
    int capacity = 0;
    int left_max = height[0];//���԰ѳ�ʼ�������
    int left_index = 0;
    for (int i = 1; i < height.size(); ++i) {
        //�ֲ���ӷ���̰����ÿ���Ҳ�������ͺ����max��Χ�����м��ˮ��ͳ�ƽ��������Ҹı����飬��ӣ������ظ�����

        if (height[i] > height[i - 1]) { //������������ʱ��������������ӣ��޸������ֵ������capacity�����ֻ���min(����max)�ĸ߶�
            int j = i - 1;
            int right_max = height[i];
            int local_max_height = std::min(left_max, right_max);//ˮͰȡ�̰�

            while (j > left_index) {//��������ߵ�����е� 
                if (height[j] < local_max_height) {//���ܰѸߵ�ĵ�
                    capacity += local_max_height - height[j];//ͳ��ˮ��
                    height[j] = local_max_height;//��ƽ����(���ǲ������ͣ����ӣ�5,3,1,2��
                }
                j--;
            }
        }

        if (height[i] > left_max) {//����ˮͰ���,��ʹҪ����ˮͰ��ҲҪ������м����ӵ���������5,1,1,1��6
            left_max = height[i];
            left_index = i;//ˢ�����±�
        }
    }
    return capacity;
}

int Solution_0xx::trap_BF(std::vector<int>& height) {
    if (height.size() < 2)//����2�������ܽ�ˮ
        return 0;

    int capacity = 0;
    for (int i = 1; i < height.size(); ++i) {
        //�Ե�ǰ����Ϊ�ӽǣ�������max
        int left_max = 0;
        int right_max = 0;
        for (int j = 0; j < i; j++) {
            left_max = std::max(left_max, height[j]);
        }
        for (int k = i + 1; k < height.size(); ++k) {
            right_max = std::max(right_max, height[k]);
        }

        if (height[i] < std::min(left_max, right_max))
            capacity += std::min(left_max, right_max) - height[i];
    }
    return capacity;
}

int Solution_0xx::trap_BF2(std::vector<int>& height) {
    const int n = height.size();
    int ans = 0;
    auto sit = cbegin(height);
    auto eit = cend(height);
    for (int i = 0; i < n; ++i) {
        int l = *max_element(sit, sit + i + 1);//�������Լ�������һ���߼��򻯵�ԭ������max���������Լ���min(l,r)Ҳ�Ͱ����Լ���������Լ�С,��һ�����DP����Ҳ�ܹؼ�������ĳһ�������ļ���
        int r = *max_element(sit + i, eit);
        ans += std::min(l, r) - height[i];
    }
    return ans;
}


int Solution_0xx::trap_DP(std::vector<int>& height) {
    int n = height.size();
    int ans = 0;
    std::vector<int> max_l(n);
    std::vector<int> max_r(n);//ֱ��Ԥ���ĺô��ǿ���β��,����ͷ����reverse

    for (int i = 0; i < n; ++i) {//DP�������̣�i�±귴����iter����
        max_l[i] = i == 0 ? height[i] : std::max(max_l[i - 1], height[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        max_r[i] = i == n - 1 ? height[i] : std::max(max_r[i + 1], height[i]);
    }

    for (int i = 0; i < n; ++i) {
        ans += std::min(max_l[i], max_r[i]) - height[i];
    }
    return ans;
}

int Solution_0xx::trap(std::vector<int>& height) {
    //˼·��ͬʱ����ָ���ƶ�����̬����max_l��max_r������ͬʱ��̬��ӣ�˫ָ���Ͻ���
    int n = height.size();
    if (n <= 2)
        return 0;
    int ans = 0;
    int index_l = 0;
    int max_l = height[index_l];
    int index_r = n - 1;
    int max_r = height[index_r];
    //˫ָ����ƶ����Բ��Ǿ��裺˭С�ƶ�˭��ͬʱ�ƶ���������
    //����Ĺؼ��ǣ����һ��Ӵ��С����Ϊ��һ��Ҳû�ж��ף��㲻ȷ����ʱ��Ӧ�üӼ������С���ǲฺ���ƶ���������ȷ�����Ա������ֵ��������
    while (index_l < index_r) {
        if (max_l < max_r)
        {
            ans += max_l - height[index_l];//��Ϊ��ǰ�������Լ������Բ���õ�����
            max_l = std::max(max_l, height[++index_l]);//ֱ�Ӱ��Լ����½�ȥ����һ���Ĺ�ʽд������
        }
        else {
            ans += max_r - height[index_r];
            max_r = std::max(max_r, height[--index_r]);
        }
    }
    return ans;

}



double Solution_0xx::newtonSqrt(double n) {
    double x0 = n;
    while (abs(x0*x0 - n) >= 1e-6) {
        x0 = 0.5*(n / x0 + x0);
    }
    return x0;
}



void Solution_0xx::merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int insert_index = m + n - 1;
    int p1 = m - 1;
    int p2 = n - 1;

    while (p1 >= 0 && p2 >= 0 && insert_index >= 0) {
        if (nums1[p1] > nums2[p2])
            nums1[insert_index--] = nums1[p1--];
        else
            nums1[insert_index--] = nums2[p2--];
    }
    //��ʣһ������û�б�����:nums1�������
    while (p2 >= 0)
        nums1[insert_index--] = nums2[p2--];

}

