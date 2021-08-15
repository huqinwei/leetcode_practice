#include "Solution_57x.h"


//要判断完全一致性
inline bool is_same_value_structure(TreeNode* root,TreeNode*subRoot){
    //空集都不是吧（但是迭代的子树没有预先判定，所以可能传空，所以并集双空应该是true）
    //比左神的暴力法少了一次判断，他的会冗余一点，用了三个条件计算左右不等
    if (root == NULL && subRoot == NULL)
        return true;
    if (root == NULL || subRoot == NULL)
        return false;
    if (root->val != subRoot->val)
        return false;
    //终止条件？当前值相等，又没有子树
    if (!root->left && !root->right && !subRoot->left && !subRoot->right)
        return true;
    return (is_same_value_structure(root->left, subRoot->left)//这时候subRoot也要递归了，其他时候subRoot是不用递归的
        && is_same_value_structure(root->right, subRoot->right)
        );
}
//先判断前置条件
bool Solution_57x::isSubtree_bruteforce(TreeNode* root, TreeNode* subRoot) {
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



