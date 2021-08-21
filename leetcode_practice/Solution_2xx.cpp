#include "Solution_2xx.h"




ListNode* Solution_2xx::reverseList(ListNode* head) {
    if (!head)
        return head;
    ListNode* nxt = head->next;
    if (nxt) {//�ݹ�����
        nxt = reverseList(nxt);//�ֲ���ת
        nxt->next = head;
        head->next = NULL;
        return nxt;
    }
    return head;;
}



//���⣺���mask==1��grid===0����һ�������ã�ֱ�Ӱ�grid��Ϊ��ͺ��ˣ�
//�Ƿ���Ϊ���ʹ�������ͨ���жϣ�����Ҳ���ᣡDFS���Ǹ������еľ���������ȥ���������ˣ������ľ��ò����ˣ������Ǳ�׼��������
//�����ô���û�޸�ԭʼ����
inline void islands_DFS(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>> &mask,int i,int j) {
    if (mask[i][j]||grid[i][j]=='0')//ֹͣ���������ʹ������߲��ǵ���
        return;
    mask[i][j] = true;//���ʱ��
    //�ݹ�//�����Խ��
    if (i+1<grid.size()) {
        islands_DFS(grid, mask, i + 1, j);
    }
    if (j + 1 < grid[0].size()) {
        islands_DFS(grid, mask, i, j+1);
    }
    if (i - 1 >= 0) {
        islands_DFS(grid, mask, i - 1, j);
    }
    if (j - 1 >= 0) {
        islands_DFS(grid, mask, i, j - 1);
    }

}

int Solution_2xx::numIslands_DFS_mask(std::vector<std::vector<char>>& grid) {
    int height = grid.size();
    int width = grid[0].size();
    int islands = 0;

    //�����߼���Ҫ�Բ������⣬����Ϊ��������ˣ�˫��ѭ����ֵ��ʼ��һ��O(N)��������
    std::vector<std::vector<bool>> mask(height);
    for (auto it = mask.begin(); it != mask.end(); it++) {
        it->resize(width);
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == '1'&&!mask[i][j])//����������0�����룬ע����char����
            {
                islands_DFS(grid, mask, i, j);
                islands++;
            }
        }
    }

    return islands;
}


//ԭ���޸�ԭ���ݣ�����mask
//if������ﻹ������࣬���Է�����ڼ�飬���Ƕ�Ҫ��飬���
inline void islands_DFS_inplace(std::vector<std::vector<char>>& grid, int i, int j) {
    if (grid[i][j] == '0')//ֹͣ���������ʹ������߲��ǵ���
        return;
    grid[i][j] = '0';//���ʱ��
//�ݹ�//�����Խ��
    if (i + 1 < grid.size()) {
        islands_DFS_inplace(grid,  i + 1, j);
    }
    if (j + 1 < grid[0].size()) {
        islands_DFS_inplace(grid,  i, j + 1);
    }
    if (i - 1 >= 0) {
        islands_DFS_inplace(grid,  i - 1, j);
    }
    if (j - 1 >= 0) {
        islands_DFS_inplace(grid,  i, j - 1);
    }
}

int Solution_2xx::numIslands_inplace(std::vector<std::vector<char>>& grid) {
    int height = grid.size();
    int width = grid[0].size();
    int islands = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == '1')//����������0�����룬ע����char����
            {
                islands_DFS_inplace(grid, i, j);
                islands++;
            }
        }
    }
    return islands;
}



//ԭ���޸�ԭ���ݣ�����mask
//if������ﻹ������࣬���Է�����ڼ�飬���Ƕ�Ҫ��飬���
inline void islands_BFS_inplace(std::vector<std::vector<char>>& grid, std::queue<std::pair<int, int>> &q,int i, int j) {
    while (q.size()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (grid[i][j] == '0')//ֹͣ���������ʹ������߲��ǵ���
            continue;
        grid[i][j] = '0';//���ʱ��
        if (i + 1 < grid.size()) {
            q.push(std::make_pair(i + 1, j));
        }
        if (j + 1 < grid[0].size()) {
            q.push(std::make_pair(i, j + 1));
        }
        if (i - 1 >= 0) {
            q.push(std::make_pair(i - 1, j));
        }
        if (j - 1 >= 0) {
            q.push(std::make_pair(i, j - 1));
        }
    }
}

int Solution_2xx::numIslands_BFS(std::vector<std::vector<char>>& grid) {
    int height = grid.size();
    int width = grid[0].size();
    int islands = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == '1')//����������0�����룬ע����char����
            {
                std::queue<std::pair<int, int>> q;
                q.push(std::make_pair(i, j));
                islands_BFS_inplace(grid, q,i, j);
                islands++;
            }
        }
    }
    return islands;
}



int Solution_2xx::rob_II(vector<int>& nums) {
    //�Ȱ汾һ�ѣ���Ϊ�Ǹ�dp���Լ�����û�У�����������һȦȴ������һ����״̬
    //��ʵҲ���ѣ���ȽϺ��һ�������ǽ�����
    //˼·����Ȼ��dp�����㵽��dp[i-1]�������ѡȡdp[i-1]����ѡȡdp[i]��ʱ�����ǲ�֪��nums[0]������û�б�ѡ�е�
    //dp[i-1]�������߲�����nums[0]�����ڸ��Ƿ�Χ�ڣ����Ե�����dp�ǲ����жϱջ���
    //�����ǲ�����飺��0��ʼһ�飬��1��ʼһ�飬��0��ʼ�������յ�����i-1����1��ʼ���������i�������ڶ����������ܿ�nums[0]�����
    //���ղ������������ս��ȡmax
    int n = nums.size();
    if (n < 2)
        return nums[0];
    if (n < 3)//���Ҫ�����ڶ���dp�����ٳ���Ϊ3
        return max(nums[0], nums[1]);

    //��һ����ڶ���ϲ���ע��ֱ����ѭ����������
    vector<int> dp(n);
    vector<int> dp_(n + 2);//һ����Ϊ���±�ͳһ��һ����Ҫ�����������������n+2����dp��2
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    dp_[1] = nums[1];
    dp_[2] = max(nums[1], nums[2]);

    for (int i = 2; i < n; ++i) {
        if (i < n - 1) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        if (i >= 3) {
            dp_[i] = max(nums[i] + dp_[i - 2], dp_[i - 1]);
        }
    }

    return std::max(dp[n - 2], dp_[n-1]);
}
bool Solution_2xx::containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> sets;
    for (int i = 0; i < nums.size(); ++i) {
        if (sets.find(nums[i]) != sets.end())
            return true;
        sets.insert(nums[i]);
    }

    return false;
}


bool  Solution_2xx::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int i = 0;
    int j = matrix[0].size() - 1;

    while (i >= 0 && i < matrix.size() && j >= 0 && j < matrix[0].size()) {
        if (matrix[i][j] < target) {
            i++;
        }
        else if (matrix[i][j] > target) {
            j--;
        }
        else {
            return true;
        }
    }
    return false;
}




long long Solution_2xx::badversion_recursion(long long start, long long end) {//int���ݲ�����
    if (end == start) {//��ֹ����
        if (isBadVersion(start))
            return start;
        else
            return start + 1;
    }
    long long mid = (start + end) / 2;
    if (isBadVersion(mid))//�����bad��������
        return badversion_recursion(start, mid);
    else
        return badversion_recursion(mid + 1, end);
}

int Solution_2xx::firstBadVersion(int n) {
    //����������������Χ��1��n
    return badversion_recursion(1, n);
}

void Solution_2xx::moveZeroes(std::vector<int>& nums) {

    int n = nums.size();
    if (n < 2)
        return;
    int slow = 0,fast = 0;//fast��Ҫ��ʼ������

    while (fast < n) {
        while (fast < n && nums[fast] == 0) {//������̲��õ�����ʼ��һ�Σ��ŵ�ѭ�����ɣ�&&����˳��д������Խ��
            fast++;
        }
        if (fast >= n)//��ǰ��ֹ
            break;
        nums[slow] = nums[fast];
        slow++;
        fast++;
    }
    while (slow < n) {//��������
        nums[slow] = 0;
        slow++;
    }

}






