#include "Solution_7xx.h"


  int search_recursion(std::vector<int>& nums,int start,int end, int target) {
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

void floodFill_DFS_recursion() {

}

vector<vector<int>> Solution_7xx::floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    vector<vector<int>> res(image);

    int height = res.size();
    int width = res[0].size();

	vector<vector<int>> visited(res.size());
    for (int i = 0; i < visited.size(); ++i) {
        visited[i].resize(res[0].size());
    }
    int target_value = image[sr][sc];//可以用char来改善内存大小

    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    while (q.size()) {
        auto data = q.front();
        q.pop();
        int curr_row = data.first;
		int curr_col = data.second;
		visited[curr_row][curr_col] = 1;//访问
        res[curr_row][curr_col] = newColor;//上色

		if (curr_row + 1 < height && image[curr_row + 1][curr_col] ==target_value && !visited[curr_row + 1][curr_col]) {
			q.push(make_pair(curr_row + 1, curr_col));
		}
		if (curr_row - 1 >= 0 && image[curr_row - 1][curr_col] == target_value && !visited[curr_row - 1][curr_col]) {
			q.push(make_pair(curr_row - 1, curr_col));
		}
		if (curr_col + 1 < width && image[curr_row][curr_col + 1] == target_value && !visited[curr_row][curr_col+1]) {
			q.push(make_pair(curr_row, curr_col + 1));
		}
		if (curr_col - 1 >= 0 && image[curr_row][curr_col - 1] == target_value && !visited[curr_row][curr_col - 1]) {
			q.push(make_pair(curr_row, curr_col - 1));
		}
    }
    return res;
}

vector<vector<int>> Solution_7xx::floodFill_trick(vector<vector<int>>& image, int sr, int sc, int newColor) {
	//取巧思路：不做visited，直接原地修改
	int height = image.size();
	int width = image[0].size();

	int target_value = image[sr][sc];//可以用char来改善内存大小

	queue<pair<int, int>> q;
	q.push(make_pair(sr, sc));
	while (q.size()) {
		auto data = q.front();
		q.pop();
		int curr_row = data.first;
		int curr_col = data.second;
        image[curr_row][curr_col] = newColor;//上色

		if (curr_row + 1 < height && (image[curr_row + 1][curr_col] == target_value )) {
			q.push(make_pair(curr_row + 1, curr_col));
		}
		if (curr_row - 1 >= 0 && image[curr_row - 1][curr_col] == target_value) {
			q.push(make_pair(curr_row - 1, curr_col));
		}
		if (curr_col + 1 < width && image[curr_row][curr_col + 1] == target_value ) {
			q.push(make_pair(curr_row, curr_col + 1));
		}
		if (curr_col - 1 >= 0 && image[curr_row][curr_col - 1] == target_value ) {
			q.push(make_pair(curr_row, curr_col - 1));
		}
	}
	return image;
}

//实现思路：一共n的台阶，最终要到达的是台阶之外，也就是[n]，这个位置赋值0，然后dp动态寻找从前两个位置谁更合适
int Solution_7xx::minCostClimbingStairs(std::vector<int>& cost) {
    //终止条件：跨过最后一个元素，隐含条件，起点可以选择
    int n = cost.size();//下标要注意
    if (n == 0 || n == 1)
        return 0;//都可以直接跳过

    cost.push_back(0);//终点位置没有开销，为了照顾通式cost[i]
    
    //if (n == 2)//也可以被覆盖//去了这个if语句，居然快了一倍？
        //return std::min(cost[0], cost[1]);
    std::vector<int> dp(n + 1);
    dp[0] = cost[0];
    dp[1] = cost[1];

     //核心逻辑，dp[i]=min(dp[i-1],dp[i-2])//是否原地修改cost，最好不要（好想可以）
    for (int i = 2; i <= n; ++i) {
        dp[i] = cost[i] + std::min(dp[i - 2], dp[i - 1]);
    }
    //终止位置应该是dp[n]，也就是跨过所有楼梯的“新位置”，原来下标是0,1,2，目标下标是3
    return dp[n];

}

bool Solution_7xx::rotateString(std::string s, std::string goal) {

    return false;
}