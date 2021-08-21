#include "Solution_7xx.h"


inline int search_recursion(std::vector<int>& nums,int start,int end, int target) {
    int n = end-start+1;
    if (n <= 0)
        return -1;
    int mid = (start+end) / 2;

    if (target == nums[mid])
        return mid;
    else if (target < nums[mid])
        return search_recursion(nums, start, mid - 1, target);
    else
        return search_recursion(nums, mid + 1, end, target);
}

int Solution_7xx::search(std::vector<int>& nums, int target) {
    int n = nums.size();
    return search_recursion(nums, 0, n-1,target);

}


//ʵ��˼·��һ��n��̨�ף�����Ҫ�������̨��֮�⣬Ҳ����[n]�����λ�ø�ֵ0��Ȼ��dp��̬Ѱ�Ҵ�ǰ����λ��˭������
int Solution_7xx::minCostClimbingStairs(std::vector<int>& cost) {
    //��ֹ������������һ��Ԫ�أ�����������������ѡ��
    int n = cost.size();//�±�Ҫע��
    if (n == 0 || n == 1)
        return 0;//������ֱ������

    cost.push_back(0);//�յ�λ��û�п�����Ϊ���չ�ͨʽcost[i]
    
    //if (n == 2)//Ҳ���Ա�����//ȥ�����if��䣬��Ȼ����һ����
        //return std::min(cost[0], cost[1]);
    std::vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

     //�����߼���dp[i]=min(dp[i-1],dp[i-2])//�Ƿ�ԭ���޸�cost����ò�Ҫ��������ԣ�
    for (int i = 2; i <= n; ++i) {
        dp[i] = cost[i] + std::min(dp[i - 2], dp[i - 1]);
    }
    //��ֹλ��Ӧ����dp[n]��Ҳ���ǿ������¥�ݵġ���λ�á���ԭ���±���0,1,2��Ŀ���±���3
    return dp[n];

}

bool Solution_7xx::rotateString(std::string s, std::string goal) {

    return false;
}