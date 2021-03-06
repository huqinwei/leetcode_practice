#include "Solution_1xx.h"



int Solution_1xx::maxProfit_II(std::vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i < prices.size()-1; ++i) {
        if (prices[i] > prices[i + 1])
            continue;
        profit += prices[i + 1] - prices[i];
    }
    return profit;
}


void Solution_1xx::rotate(std::vector<int>& nums, int k) {
    if (nums.size() <= 1)
        return;
    k = k%nums.size();
    //全翻转
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    //左侧翻转
    i = 0;
    j = k - 1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    //右侧翻转
    i = k;
    j = nums.size()-1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    

}


int Solution_1xx::rob_II(std::vector<int>& nums) {
    //迭代逻辑：假设数据只有当前这么长，不看下一长度
    int n = nums.size();

    if (n < 1)
        return 0;
    if (n == 1)
        return nums[0];

    std::vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = std::max(nums[0], nums[1]);

    //核心公式：当前的加上前跳一步的累积是否大于前一步的累积
    for (int i = 2; i < n; i++) {
        dp[i] = std::max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[n - 1];
}


int Solution_1xx::singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
        result ^= nums[i];
    return result;
}


int Solution_1xx::singleNumber_by_map(std::vector<int>& nums) {
    //不过这个题确实不是很适合用字典：因为有插入过程，不是碰到成双的返回，是碰到落单的返回，意味着需要遍历结束，遍历结束后？还需要遍历一下字典来找到value为1的
    int result = 0;
    std::unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); i++) {
        dict[nums[i]] += 1;
    }

    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        if (iter->second == 1)
            return iter->first;
    }
    return result;
}
  void preorder_recuision(TreeNode* root, vector<int> &res_vec) {
	//前序：根左右
    if (!root)//stop
        return;

	res_vec.push_back(root->val);
    preorder_recuision(root->left, res_vec);
    preorder_recuision(root->right, res_vec);
}

vector<int> Solution_1xx::preorderTraversal(TreeNode* root) {
	vector<int> res_vec;
    preorder_recuision(root, res_vec);
	return res_vec;
}
vector<int> Solution_1xx::levelOrderTraversal(TreeNode* root) {
    //返回要求vector<vector<int>> ，可以给根赋level值，然后入队列时候存储，这样直接找一个合适的位置放在vector？
    //或者交替使用queue，一个队列空了，切换到另一个
    //
    queue<TreeNode*> stack;
	vector<int> res_vec;
    if (!root)
        return res_vec;
    stack.push(root);
    while (stack.size()) {
        TreeNode* curr = stack.front();
		stack.pop();
        res_vec.push_back(curr->val);
		if (curr->left)
			stack.push(curr->left);
		if (curr->right)
			stack.push(curr->right);
    }
	return res_vec;
}


/* */ void postorder_recuision(TreeNode* root, vector<int>& res_vec) {
	if (!root)//stop
		return;

    postorder_recuision(root->left, res_vec);
	postorder_recuision(root->right, res_vec);
	res_vec.push_back(root->val);
}

vector<int> Solution_1xx::postorderTraversal(TreeNode* root) {
	vector<int> res_vec;
    postorder_recuision(root, res_vec);
	return res_vec;
}


int Solution_1xx::majorityElement_by_sort(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}
int Solution_1xx::majorityElement(std::vector<int>& nums) {
    int winner_count = 0;
    int winner_value = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (winner_count == 0) {
            winner_value = nums[i];
            winner_count++;
        }
        else if (winner_value == nums[i]) {
            winner_count++;
        }
        else if (winner_value != nums[i]) {
            winner_count--;
        }
    }
    return winner_value;
}

/* */ long long get_curr_version(std::string &s, int &ind) {
    long long v = 0;
    while (ind < s.size() && s[ind] >= '0'&&s[ind] <= '9') {
        v = v * 10 + s[ind] - '0';
        ind++;
    }
    return v;
}


int Solution_1xx::compareVersion_iteration(std::string version1, std::string version2) {
    //迭代法
    int ind1 = 0, ind2 = 0;
    while (ind1 < version1.size() || ind2 < version2.size()) {
        long long num1 = get_curr_version(version1, ind1);
        long long num2 = get_curr_version(version2, ind2);
        if (num1 < num2)
            return -1;
        if (num1 > num2)
            return 1;
        ind1++;
        ind2++;

    }
    return 0;
}

vector<int> Solution_1xx::twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    std::vector<int> ret(2);
    if (n < 2)
        return ret;
    int i = 0;
    int j = n - 1;
    while (i < j) {
        if (numbers[i] + numbers[j] > target)
            j--;
        else if (numbers[i] + numbers[j] < target)   //使用互斥条件，一次只移动一个指针
            i++;
        else {
            return{ i + 1,j + 1 };//vector可以返回的形式//题目要求的下标规则
        }
    }
    return ret;
}


int Solution_1xx::compareVersion(std::string version1, std::string version2) {
    //拿到当前版本号
    //如果一方有而一方没有，则前者版本号大（也不一定，可能是1.和1.0）
    int n1 = version1.length();
    int n2 = version2.length();

    if (n1 == 0 && n2 == 0)
        return 0;

    //迭代
    int index_1 = 0;
    int v1 = 0;
    while (index_1 < n1&&version1[index_1] != '.') {
        v1 = v1 * 10 + version1[index_1] - '0';
        index_1++;
    }
    if (version1[index_1] == '.')
        index_1++;

    int index_2 = 0;
    int v2 = 0;
    while (index_2 < n2 && version2[index_2] != '.') {
        v2 = v2 * 10 + version2[index_2] - '0';
        index_2++;
    }
    if (version2[index_2] == '.')
        index_2++;

    //如果当前版本号不相同   返回值
    if (v1 > v2)
        return 1;
    else if (v1 < v2)
        return -1;

    //如果当前版本号相同
    //递归下一层版本号
    //递归比较麻烦的是，如果后边一个没有，也就是1.   另一个有，是1.0，怎么停止合适？下一层评估字符串是否为空
    return compareVersion(version1.substr(index_1, index_1 >= n1 ? 0 : n1 - index_1),
        version2.substr(index_2, index_2 >= n2 ? 0 : n2 - index_2));

}





