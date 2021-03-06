#include "Solution_5xx.h"


//要判断完全一致性
  bool is_same_value_structure(TreeNode* root,TreeNode*subRoot){
    //空集都不是吧（但是迭代的子树没有预先判定，所以可能传空，所以并集双空应该是true）
    //比左神的暴力法少了一次判断，他的会冗余一点，用了三个条件计算左右不等
    if (root == NULL && subRoot == NULL)
        return true;
    if (root == NULL || subRoot == NULL)
        return false;
    if (root->val != subRoot->val)
        return false;
    //终止条件:当前值相等，又没有子树
    if (!root->left && !root->right && !subRoot->left && !subRoot->right)
        return true;
    return (is_same_value_structure(root->left, subRoot->left)//这时候subRoot也要递归了，其他时候subRoot是不用递归的
        && is_same_value_structure(root->right, subRoot->right)
        );
}
//先判断前置条件
bool Solution_5xx::isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot) {
    //先判断谁是空？如果子树是空，应该是包含的（但是用例没有测出来，此处返回true也答题正确
    if (subRoot == NULL) {
        return true;
    }
    //如果子树不是空，根又是空，也不包含
    if (root == NULL) {
        return false;
    }
    //如果root和subroot完全一样，返回true，不递归
    if (is_same_value_structure(root,subRoot)) {
        return true;
    }
    //如果不一样，再暴力匹配左右子树
    return (isSubtree_bruteforce(root->left,subRoot)
        || isSubtree_bruteforce(root->right,subRoot));

}




int Solution_5xx::fib_mine(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib_mine(n - 1) + fib_mine(n - 2);
}

// int Solution_50x::fib(int n) {
//     if (n < 2) {
//         return n;
//     }
//     int p = 0, q = 0, r = 1;
// 
//     //滑块，数轴上的“下标”
//     for (int i = 2; i <= n; ++i) {
//         p = q;
//         q = r;
//         r = p + q;
//     }
//     return r;
// }


int Solution_5xx::fib(int n) {
    if (n < 2)
        return n;

    //考虑到n可以是0，可以把n看成从0起的下标，n==2时应该返回下标2，也就是0+1=1,n==3时，返回下标3，也就是1+1=2
    int p = -1, q = 0, r = 1;//初始化的值很重要，如果n==2算是滑动了一个窗口，那么q和r就是0和1，p无所谓
    for (int i = 2; i <= n; ++i) {
        p = q;
        q = r;
        r = p + q;
        std::cout << "slide window:" << p << " " << q << " " << r << std::endl;//滑窗演示
    }
    return r;
}

  void swap(string&s, int i, int j)
{
    char tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
  void reverse_single_word(string&s, int i, int j) {
    while (i < j) {
        swap(s, i++, j--);
    }
}
string Solution_5xx::reverseWords(string s) {
    //先做一个大循环，找单词，再用一个小循环，翻转单词
    int n = s.size();
    int i = 0;
    int j = 0;
    while (j < n) {
        while (i < n&&s[i] == ' ')//每一次找好i
            i++;
        j = i;
        while (j < n&&s[j] != ' ')
            j++;
        reverse_single_word(s, i, j - 1);
        i = j;
    }
    return s;
}


bool Solution_5xx::checkInclusion(string s1, string s2) {
    //借鉴思路：两个知识点：vector可以直接比较；设计巧妙的vector更新方式也很快速
    int window_size = s1.size();
    if (window_size > s2.size())//测试集存在s2更短
        return false;

    vector<int> hashtable1(26, 0);
    vector<int> hashtable2(26, 0);
	for (int i = 0; i < window_size; ++i) {
		hashtable1[s1[i] - 'a']++;
		hashtable2[s2[i] - 'a']++;
    }
    if (hashtable1 == hashtable2)//如果这里不加一次，循环的判断要写在更新之前，结尾会丢一次循环的判断
        return true;
	for (int i = window_size; i < s2.size(); ++i) {//动态更新哈希表2
		hashtable2[s2[i-window_size] - 'a']--;//这里i是窗口右侧
		hashtable2[s2[i] - 'a']++;
		if (hashtable1 == hashtable2)
			return true;
    }
    return false;
}



  void preorder_recuision(Node* root, vector<int>& res_vec) {
	//前序：根左右
	if (!root)//stop
		return;
	res_vec.push_back(root->val);
	for (auto it = root->children.begin(); it != root->children.end(); ++it) {
        preorder_recuision(*it, res_vec);
    }
}

vector<int> Solution_5xx::preorder(Node* root) {
	vector<int> res_vec;
    preorder_recuision(root, res_vec);
	return res_vec;
}



/* */ void postorder_recuision(Node* root, vector<int>& res_vec) {
	//前序：根左右
	if (!root)//stop
		return;
	for (auto it = root->children.begin(); it != root->children.end(); ++it) {
        postorder_recuision(*it, res_vec);
	}
	res_vec.push_back(root->val);
}

vector<int> Solution_5xx::postorder(Node* root) {
	vector<int> res_vec;
    postorder_recuision(root, res_vec);
	return res_vec;
}