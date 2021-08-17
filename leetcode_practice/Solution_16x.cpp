#include "Solution_16x.h"


int Solution_16x::majorityElement_by_sort(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}
int Solution_16x::majorityElement(std::vector<int>& nums) {
    int winner_count = 0;
    int winner_value = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (winner_count == 0){
            winner_value = nums[i];
            winner_count++;
        }
        else if (winner_value == nums[i]){
            winner_count++;
        }
        else if (winner_value != nums[i]){
            winner_count--;
        }
    }
    return winner_value;
}

inline long long get_curr_version(std::string &s,int &ind) {
    long long v = 0;
    while (ind < s.size() && s[ind] >= '0'&&s[ind] <= '9') {
        v = v * 10 + s[ind] - '0';
        ind++;
    }
    return v;
}


int Solution_16x::compareVersion_iteration(std::string version1, std::string version2) {
    //������
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


int Solution_16x::compareVersion(std::string version1, std::string version2) {
    //�õ���ǰ�汾��
    //���һ���ж�һ��û�У���ǰ�߰汾�Ŵ�Ҳ��һ����������1.��1.0��
    int n1 = version1.length();
    int n2 = version2.length();

    if (n1 == 0 && n2 == 0)
        return 0;

    //����
    int index_1 = 0;
    int v1=0;
    while (index_1<n1&&version1[index_1] != '.') {
        v1 = v1 * 10 + version1[index_1] - '0';
        index_1++;
    }
    if (version1[index_1] == '.')
        index_1++;

    int index_2 = 0;
    int v2=0;
    while (index_2 < n2 && version2[index_2] != '.') {
        v2 = v2 * 10 + version2[index_2] - '0';
        index_2++;
    }
    if (version2[index_2] == '.')
        index_2++;

    //�����ǰ�汾�Ų���ͬ   ����ֵ
    if (v1 > v2)
        return 1;
    else if (v1 < v2)
        return -1;

    //�����ǰ�汾����ͬ
    //�ݹ���һ��汾��
    //�ݹ�Ƚ��鷳���ǣ�������һ��û�У�Ҳ����1.   ��һ���У���1.0����ôֹͣ���ʣ���һ�������ַ����Ƿ�Ϊ��
    return compareVersion(version1.substr(index_1,index_1>=n1?0:n1-index_1),
        version2.substr(index_2, index_2 >= n2 ? 0 : n2 - index_2));

}