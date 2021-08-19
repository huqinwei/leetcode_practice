



#include "Solution_0xx.h"


std::vector<int> Solution_0xx::twoSum(std::vector<int>& nums, int target) {
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

std::vector<int> Solution_0xx::twoSum_brute(std::vector<int>& nums, int target) {
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





std::vector<int> Solution_0xx::twoSum_2points(std::vector<int>& nums, int target) {

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


ListNode* Solution_0xx::addTwoNumbers_iteration(ListNode* l1, ListNode* l2) {
    ListNode*ret = new ListNode();
    ListNode*cur = ret;
    bool carry = 0;
    while (l1 != NULL || l2 != NULL || carry) {
        int tmp = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;//优先级有问题，必须括号
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

//还有一个方法把carry附加到l1或者l2。
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
    //简单的堆栈判断，控制栈容器的通道，写一些具体符号的判断
    //给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
    std::vector<char> stack;
    for (int i = 0; i < s.size(); ++i) {
        //std::cout << s[i] << " ";
        if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.size() == 0)
                return false;
            char tmp = stack.back();//其实先pop出来也没问题的，两种结局，一种是return false，一种是pop
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
std::vector<std::string> Solution_0xx::generateParenthesis(int n) {
    std::vector<std::string> res;
    back_tracking(n, res, 0, 0, "");
    return res;
}

ListNode* Solution_0xx::swapPairs(ListNode* head) {
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



inline int searchInsert_recursion_old(std::vector<int>& nums, int start, int end, int target) {
    if (end < start)//关于插入，结束条件需要注意，因为我的实现mid-1，所以mid会小于start，但是插入点应该是start，这种逻辑能通，但乱，所以优化掉
        return start;
    if (end == start) {//寻找到最后，考虑插入问题
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

//因为用了/，所以mid传参不用-1也可以完成逻辑，终止条件是start==end
//考虑情形是start=0,mid=1,
//下一次递归传入0,1
//mid是0，再下一次循环，左侧是下标0，右侧是下标1，能锁定end==start的终止条件
//到了终止条件（只剩一个数）就需要判断，是插入当前位置还是下一个位置
inline int searchInsert_recursion(std::vector<int>& nums, int start, int end, int target) {
    if (end == start) {//寻找到最后，考虑插入问题
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





//我用水桶来表达中间的沟，或者用gap
int Solution_0xx::trap_greedy(std::vector<int>& height) {
    if (height.size() < 2)//少于2都不可能接水
        return 0;
    int capacity = 0;
    int left_max = height[0];//可以把初始化放外边
    int left_index = 0;
    for (int i = 1; i < height.size(); ++i) {
        //局部填坑法：贪婪，每次右侧递增，就和左侧max合围，把中间的水量统计进来，并且改变数组，填坑，避免重复计算

        if (height[i] > height[i - 1]) { //遇到单调增的时候都逆向迭代，补坑，修改数组的值，增加capacity，最高只能填到min(左右max)的高度
            int j = i - 1;
            int right_max = height[i];
            int local_max_height = std::min(left_max, right_max);//水桶取短板

            while (j > left_index) {//不包含左高点的所有点 
                if (height[j] < local_max_height) {//不能把高点改低
                    capacity += local_max_height - height[j];//统计水量
                    height[j] = local_max_height;//填平沟壑(但是不能拉低，例子，5,3,1,2）
                }
                j--;
            }
        }

        if (height[i] > left_max) {//更新水桶左侧,即使要更新水桶，也要先算好中间增加的量，比如5,1,1,1，6
            left_max = height[i];
            left_index = i;//刷新左下标
        }
    }
    return capacity;
}

int Solution_0xx::trap_BF(std::vector<int>& height) {
    if (height.size() < 2)//少于2都不可能接水
        return 0;

    int capacity = 0;
    for (int i = 1; i < height.size(); ++i) {
        //以当前格子为视角，左右找max
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
        int l = *max_element(sit, sit + i + 1);//包含了自己，这是一个逻辑简化的原因，左右max都包含了自己，min(l,r)也就包含自己，不会比自己小,这一点对于DP方法也很关键，关于某一点容量的计算
        int r = *max_element(sit + i, eit);
        ans += std::min(l, r) - height[i];
    }
    return ans;
}


int Solution_0xx::trap_DP(std::vector<int>& height) {
    int n = height.size();
    int ans = 0;
    std::vector<int> max_l(n);
    std::vector<int> max_r(n);//直接预留的好处是可以尾插,不用头插再reverse

    for (int i = 0; i < n; ++i) {//DP的填充过程，i下标反而比iter好用
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
    //思路：同时左右指针移动，动态更新max_l和max_r，两侧同时动态填坑，双指针汇合结束
    int n = height.size();
    if (n <= 2)
        return 0;
    int ans = 0;
    int index_l = 0;
    int max_l = height[index_l];
    int index_r = n - 1;
    int max_r = height[index_r];
    //双指针的移动策略才是精髓：谁小移动谁，同时移动会有问题
    //问题的关键是，如果一侧从大变小，因为另一侧也没有兜底，你不确定这时候应该加几。如果小的那侧负责移动，可以明确就是以本侧最大值计算容量
    while (index_l < index_r) {
        if (max_l < max_r)
        {
            ans += max_l - height[index_l];//因为提前更新了自己，所以不会得到负数
            max_l = std::max(max_l, height[++index_l]);//直接把自己更新进去，下一步的公式写起来简单
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
    //还剩一个数组没有遍历完:nums1无需操作
    while (p2 >= 0)
        nums1[insert_index--] = nums2[p2--];

}

