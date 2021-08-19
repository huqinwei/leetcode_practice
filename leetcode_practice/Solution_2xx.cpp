#include "Solution_2xx.h"




ListNode* Solution_2xx::reverseList(ListNode* head) {
    if (!head)
        return head;
    ListNode* nxt = head->next;
    if (nxt) {//递归条件
        nxt = reverseList(nxt);//局部反转
        nxt->next = head;
        head->next = NULL;
        return nxt;
    }
    return head;;
}



//问题：如果mask==1和grid===0都是一样的作用，直接把grid置为零就好了？
//是否因为访问过而把连通域切断？好像也不会！DFS，那个负责切的就先深入下去并且延伸了，其他的就用不着了，绝对是标准连续蔓延
//不过好处是没修改原始数据
inline void islands_DFS(std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>> &mask,int i,int j) {
    if (mask[i][j]||grid[i][j]=='0')//停止条件：访问过，或者不是岛屿
        return;
    mask[i][j] = true;//访问标记
    //递归//如果不越界
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

    //除了逻辑必要性不足意外，还因为这里减速了，双重循环赋值初始是一个O(N)，尽量简化
    std::vector<std::vector<bool>> mask(height);
    for (auto it = mask.begin(); it != mask.end(); it++) {
        it->resize(width);
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (grid[i][j] == '1'&&!mask[i][j])//控制条件：0不进入，注意是char类型
            {
                islands_DFS(grid, mask, i, j);
                islands++;
            }
        }
    }

    return islands;
}


//原地修改原数据，不用mask
//if语句那里还不够简洁，可以放在入口检查，但是都要检查，差不多
inline void islands_DFS_inplace(std::vector<std::vector<char>>& grid, int i, int j) {
    if (grid[i][j] == '0')//停止条件：访问过，或者不是岛屿
        return;
    grid[i][j] = '0';//访问标记
//递归//如果不越界
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
            if (grid[i][j] == '1')//控制条件：0不进入，注意是char类型
            {
                islands_DFS_inplace(grid, i, j);
                islands++;
            }
        }
    }
    return islands;
}



//原地修改原数据，不用mask
//if语句那里还不够简洁，可以放在入口检查，但是都要检查，差不多
inline void islands_BFS_inplace(std::vector<std::vector<char>>& grid, std::queue<std::pair<int, int>> &q,int i, int j) {
    while (q.size()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if (grid[i][j] == '0')//停止条件：访问过，或者不是岛屿
            continue;
        grid[i][j] = '0';//访问标记
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
            if (grid[i][j] == '1')//控制条件：0不进入，注意是char类型
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




long long Solution_2xx::badversion_recursion(long long start, long long end) {//int数据不够长
    if (end == start) {//终止条件
        if (isBadVersion(start))
            return start;
        else
            return start + 1;
    }
    long long mid = (start + end) / 2;
    if (isBadVersion(mid))//如果是bad才往左找
        return badversion_recursion(start, mid);
    else
        return badversion_recursion(mid + 1, end);
}

int Solution_2xx::firstBadVersion(int n) {
    //隐含条件，搜索范围：1，n
    return badversion_recursion(1, n);
}








