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
    //ȫ��ת
    int i = 0, j = nums.size() - 1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    //��෭ת
    i = 0;
    j = k - 1;
    while (i <= j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        i++;
        j--;
    }
    //�Ҳ෭ת
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



int Solution_1xx::singleNumber(std::vector<int>& nums) {
    int result = 0;
    for (int i = 0; i < nums.size(); i++)
        result ^= nums[i];
    return result;
}


int Solution_1xx::singleNumber_by_map(std::vector<int>& nums) {
    //���������ȷʵ���Ǻ��ʺ����ֵ䣺��Ϊ�в�����̣�����������˫�ķ��أ��������䵥�ķ��أ���ζ����Ҫ�������������������󣿻���Ҫ����һ���ֵ����ҵ�valueΪ1��
    int result = 0;
    std::unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); i++) {
        dict[nums[i]] += 1;
    }

    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        if (iter->second == 1)
            return iter->first;
    }
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

inline long long get_curr_version(std::string &s, int &ind) {
    long long v = 0;
    while (ind < s.size() && s[ind] >= '0'&&s[ind] <= '9') {
        v = v * 10 + s[ind] - '0';
        ind++;
    }
    return v;
}


int Solution_1xx::compareVersion_iteration(std::string version1, std::string version2) {
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


int Solution_1xx::compareVersion(std::string version1, std::string version2) {
    //�õ���ǰ�汾��
    //���һ���ж�һ��û�У���ǰ�߰汾�Ŵ�Ҳ��һ����������1.��1.0��
    int n1 = version1.length();
    int n2 = version2.length();

    if (n1 == 0 && n2 == 0)
        return 0;

    //����
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

    //�����ǰ�汾�Ų���ͬ   ����ֵ
    if (v1 > v2)
        return 1;
    else if (v1 < v2)
        return -1;

    //�����ǰ�汾����ͬ
    //�ݹ���һ��汾��
    //�ݹ�Ƚ��鷳���ǣ�������һ��û�У�Ҳ����1.   ��һ���У���1.0����ôֹͣ���ʣ���һ�������ַ����Ƿ�Ϊ��
    return compareVersion(version1.substr(index_1, index_1 >= n1 ? 0 : n1 - index_1),
        version2.substr(index_2, index_2 >= n2 ? 0 : n2 - index_2));

}





