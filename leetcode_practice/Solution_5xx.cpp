#include "Solution_5xx.h"


//Ҫ�ж���ȫһ����
inline bool is_same_value_structure(TreeNode* root,TreeNode*subRoot){
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
bool Solution_57x::isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot) {
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




int Solution_50x::fib_mine(int n)
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


int Solution_50x::fib(int n) {
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