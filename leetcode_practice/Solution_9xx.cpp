#include "Solution_9xx.h"





std::vector<int> Solution_9xx::sortedSquares_mine(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> ret(n);
    if (n == 0)
        return ret;

    //int pivot_value = nums[0] = pow(nums[0],2);//�����˸����±�0
    int pivot_index = -1;
    int pivot_value = 1e8;


    //�˷�ʱ��������㣺�������������֣�����Ҫ�����˼����pow����in-placeд���ˣ���֪���Ƿ�ռ��ʱ��
    //ʵ���ύ������
    for (int i = 0; i < n; ++i) {
        nums[i] = pow(nums[i], 2);//����ƽ��  in place
        if (nums[i] < pivot_value) {
            pivot_index = i;
            pivot_value = nums[i];
        }
    }
    int left = pivot_index - 1;
    int right = pivot_index + 1;
    ret[0] = nums[pivot_index];//����Ҫ�ĳ�ʼ�����룿�����ʼleft==right��Ҳ����bug
    int i = 1;
    while (left >= 0 && right < n) {//����
        if (nums[left] < nums[right]) {
            ret[i++] = nums[left--];
        }
        else {
            ret[i++] = nums[right++];
        }
    }
    //�䵥��
    while (left >= 0) {
        ret[i++] = nums[left--];
    }
    while (right < n) {
        ret[i++] = nums[right++];
    }

    return ret;
}

std::vector<int> Solution_9xx::sortedSquares(std::vector<int>& nums) {
    int n = nums.size();
    int negative = -1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] < 0) {
            negative = i;
        }
        else {
            break;
        }
    }

    std::vector<int> ans;
    int i = negative, j = negative + 1;
    while (i >= 0 || j < n) {
        if (i < 0) {
            ans.push_back(nums[j] * nums[j]);
            ++j;
        }
        else if (j == n) {
            ans.push_back(nums[i] * nums[i]);
            --i;
        }
        else if (nums[i] * nums[i] < nums[j] * nums[j]) {//����ط�����������-2��+1�Ȳ���˭������
            ans.push_back(nums[i] * nums[i]);
            --i;
        }
        else {
            ans.push_back(nums[j] * nums[j]);
            ++j;
        }
    }

    return ans;

}