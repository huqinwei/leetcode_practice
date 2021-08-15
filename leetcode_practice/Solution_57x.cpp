#include "Solution_57x.h"


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
    //��ֹ��������ǰֵ��ȣ���û������
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



