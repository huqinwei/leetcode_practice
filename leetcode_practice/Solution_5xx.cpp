#include "Solution_5xx.h"


//Ҫ�ж���ȫһ����
  bool is_same_value_structure(TreeNode* root,TreeNode*subRoot){
    //�ռ������ǰɣ����ǵ���������û��Ԥ���ж������Կ��ܴ��գ����Բ���˫��Ӧ����true��
    //������ı���������һ���жϣ����Ļ�����һ�㣬�������������������Ҳ���
    if (root == NULL && subRoot == NULL)
        return true;
    if (root == NULL || subRoot == NULL)
        return false;
    if (root->val != subRoot->val)
        return false;
    //��ֹ����:��ǰֵ��ȣ���û������
    if (!root->left && !root->right && !subRoot->left && !subRoot->right)
        return true;
    return (is_same_value_structure(root->left, subRoot->left)//��ʱ��subRootҲҪ�ݹ��ˣ�����ʱ��subRoot�ǲ��õݹ��
        && is_same_value_structure(root->right, subRoot->right)
        );
}
//���ж�ǰ������
bool Solution_5xx::isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot) {
    //���ж�˭�ǿգ���������ǿգ�Ӧ���ǰ����ģ���������û�в�������˴�����trueҲ������ȷ
    if (subRoot == NULL) {
        return true;
    }
    //����������ǿգ������ǿգ�Ҳ������
    if (root == NULL) {
        return false;
    }
    //���root��subroot��ȫһ��������true�����ݹ�
    if (is_same_value_structure(root,subRoot)) {
        return true;
    }
    //�����һ�����ٱ���ƥ����������
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
//     //���飬�����ϵġ��±ꡱ
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

    //���ǵ�n������0�����԰�n���ɴ�0����±꣬n==2ʱӦ�÷����±�2��Ҳ����0+1=1,n==3ʱ�������±�3��Ҳ����1+1=2
    int p = -1, q = 0, r = 1;//��ʼ����ֵ����Ҫ�����n==2���ǻ�����һ�����ڣ���ôq��r����0��1��p����ν
    for (int i = 2; i <= n; ++i) {
        p = q;
        q = r;
        r = p + q;
        std::cout << "slide window:" << p << " " << q << " " << r << std::endl;//������ʾ
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
    //����һ����ѭ�����ҵ��ʣ�����һ��Сѭ������ת����
    int n = s.size();
    int i = 0;
    int j = 0;
    while (j < n) {
        while (i < n&&s[i] == ' ')//ÿһ���Һ�i
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
    //���˼·������֪ʶ�㣺vector����ֱ�ӱȽϣ���������vector���·�ʽҲ�ܿ���
    int window_size = s1.size();
    if (window_size > s2.size())//���Լ�����s2����
        return false;

    vector<int> hashtable1(26, 0);
    vector<int> hashtable2(26, 0);
	for (int i = 0; i < window_size; ++i) {
		hashtable1[s1[i] - 'a']++;
		hashtable2[s2[i] - 'a']++;
    }
    if (hashtable1 == hashtable2)//������ﲻ��һ�Σ�ѭ�����ж�Ҫд�ڸ���֮ǰ����β�ᶪһ��ѭ�����ж�
        return true;
	for (int i = window_size; i < s2.size(); ++i) {//��̬���¹�ϣ��2
		hashtable2[s2[i-window_size] - 'a']--;//����i�Ǵ����Ҳ�
		hashtable2[s2[i] - 'a']++;
		if (hashtable1 == hashtable2)
			return true;
    }
    return false;
}



  void preorder_recuision(Node* root, vector<int>& res_vec) {
	//ǰ�򣺸�����
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
	//ǰ�򣺸�����
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