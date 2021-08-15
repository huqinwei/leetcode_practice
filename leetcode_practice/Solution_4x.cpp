#include "Solution_4x.h"



//����ˮͰ������м�Ĺ���������gap
int Solution_4x::trap_greedy(std::vector<int>& height) {
    if (height.size() < 2)//����2�������ܽ�ˮ
        return 0;
    int capacity = 0;
    int left_max = height[0];//���԰ѳ�ʼ�������
    int left_index = 0;
    for (int i = 1; i < height.size(); ++i) {
        //�ֲ���ӷ���̰����ÿ���Ҳ�������ͺ����max��Χ�����м��ˮ��ͳ�ƽ��������Ҹı����飬��ӣ������ظ�����
       
        if (height[i] > height[i - 1]) { //������������ʱ��������������ӣ��޸������ֵ������capacity�����ֻ���min(����max)�ĸ߶�
            int j = i-1;
            int right_max = height[i];
            int local_max_height = std::min(left_max, right_max);//ˮͰȡ�̰�

            while (j > left_index) {//��������ߵ�����е� 
                if (height[j] < local_max_height) {//���ܰѸߵ�ĵ�
                    capacity += local_max_height - height[j];//ͳ��ˮ��
                    height[j] = local_max_height;//��ƽ����(���ǲ������ͣ����ӣ�5,3,1,2��
                }
                j--;
            }
        }

        if (height[i] > left_max) {//����ˮͰ���,��ʹҪ����ˮͰ��ҲҪ������м����ӵ���������5,1,1,1��6
            left_max = height[i];
            left_index = i;//ˢ�����±�
        }
    }
    return capacity;
}

int Solution_4x::trap_BF(std::vector<int>& height) {
    if (height.size() < 2)//����2�������ܽ�ˮ
        return 0;

    int capacity = 0;
    for (int i = 1; i < height.size(); ++i) {
        //�Ե�ǰ����Ϊ�ӽǣ�������max
        int left_max = 0;
        int right_max = 0;
        for (int j = 0; j < i; j++) {
            left_max = std::max(left_max, height[j]);
        }
        for (int k = i + 1; k < height.size(); ++k) {
            right_max = std::max(right_max, height[k]);
        }
        
        if(height[i]<std::min(left_max, right_max))
            capacity += std::min(left_max, right_max)-height[i];
    }
    return capacity;
}

int Solution_4x::trap_BF2(std::vector<int>& height) {
    const int n = height.size();
    int ans = 0;
    auto sit = cbegin(height);
    auto eit = cend(height);
    for (int i = 0; i < n; ++i) {
        int l = *max_element(sit, sit + i + 1);//�������Լ�������һ���߼��򻯵�ԭ������max���������Լ���min(l,r)Ҳ�Ͱ����Լ���������Լ�С,��һ�����DP����Ҳ�ܹؼ�������ĳһ�������ļ���
        int r = *max_element(sit + i, eit);
        ans += std::min(l, r) - height[i];
    }
    return ans;
}


int Solution_4x::trap_DP(std::vector<int>& height) {
    int n = height.size();
    int ans = 0;
    std::vector<int> max_l(n);
    std::vector<int> max_r(n);//ֱ��Ԥ���ĺô��ǿ���β��,����ͷ����reverse

    for (int i = 0; i < n; ++i) {//DP�������̣�i�±귴����iter����
        max_l[i] = i == 0 ? height[i] : std::max(max_l[i-1],height[i]);
    }
    for (int i =n-1; i >=0; --i) {
        max_r[i] = i == n-1 ? height[i] : std::max(max_r[i + 1], height[i]);
    }

    for (int i = 0; i < n;++i) {
        ans += std::min(max_l[i], max_r[i])-height[i];
    }
    return ans;
}

int Solution_4x::trap(std::vector<int>& height) {
    //˼·��ͬʱ����ָ���ƶ�����̬����max_l��max_r������ͬʱ��̬��ӣ�˫ָ���Ͻ���
    int n = height.size();
    if (n <= 2)
        return 0;
    int ans = 0;
    int index_l = 0;
    int max_l = height[index_l];
    int index_r = n - 1;
    int max_r = height[index_r];
    //˫ָ����ƶ����Բ��Ǿ��裺˭С�ƶ�˭��ͬʱ�ƶ���������
    //����Ĺؼ��ǣ����һ��Ӵ��С����Ϊ��һ��Ҳû�ж��ף��㲻ȷ����ʱ��Ӧ�üӼ������С���ǲฺ���ƶ���������ȷ�����Ա������ֵ��������
    while (index_l < index_r) {
        if (max_l < max_r)
        {
            ans += max_l - height[index_l];//��Ϊ��ǰ�������Լ������Բ���õ�����
            max_l = std::max(max_l, height[++index_l]);//ֱ�Ӱ��Լ����½�ȥ����һ���Ĺ�ʽд������
        }
        else {
            ans += max_r - height[index_r];
            max_r = std::max(max_r, height[--index_r]);
        }
    }
    return ans;

}
