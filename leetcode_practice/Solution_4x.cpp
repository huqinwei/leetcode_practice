#include "Solution_4x.h"



//我用水桶来表达中间的沟，或者用gap
int Solution_4x::trap_greedy(std::vector<int>& height) {
    if (height.size() < 2)//少于2都不可能接水
        return 0;
    int capacity = 0;
    int left_max = height[0];//可以把初始化放外边
    int left_index = 0;
    for (int i = 1; i < height.size(); ++i) {
        //局部填坑法：贪婪，每次右侧递增，就和左侧max合围，把中间的水量统计进来，并且改变数组，填坑，避免重复计算
       
        if (height[i] > height[i - 1]) { //遇到单调增的时候都逆向迭代，补坑，修改数组的值，增加capacity，最高只能填到min(左右max)的高度
            int j = i-1;
            int right_max = height[i];
            int local_max_height = std::min(left_max, right_max);//水桶取短板

            while (j > left_index) {//不包含左高点的所有点 
                if (height[j] < local_max_height) {//不能把高点改低
                    capacity += local_max_height - height[j];//统计水量
                    height[j] = local_max_height;//填平沟壑(但是不能拉低，例子，5,3,1,2）
                }
                j--;
            }
        }

        if (height[i] > left_max) {//更新水桶左侧,即使要更新水桶，也要先算好中间增加的量，比如5,1,1,1，6
            left_max = height[i];
            left_index = i;//刷新左下标
        }
    }
    return capacity;
}

int Solution_4x::trap_BF(std::vector<int>& height) {
    if (height.size() < 2)//少于2都不可能接水
        return 0;

    int capacity = 0;
    for (int i = 1; i < height.size(); ++i) {
        //以当前格子为视角，左右找max
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
        int l = *max_element(sit, sit + i + 1);//包含了自己，这是一个逻辑简化的原因，左右max都包含了自己，min(l,r)也就包含自己，不会比自己小,这一点对于DP方法也很关键，关于某一点容量的计算
        int r = *max_element(sit + i, eit);
        ans += std::min(l, r) - height[i];
    }
    return ans;
}


int Solution_4x::trap_DP(std::vector<int>& height) {
    int n = height.size();
    int ans = 0;
    std::vector<int> max_l(n);
    std::vector<int> max_r(n);//直接预留的好处是可以尾插,不用头插再reverse

    for (int i = 0; i < n; ++i) {//DP的填充过程，i下标反而比iter好用
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
    //思路：同时左右指针移动，动态更新max_l和max_r，两侧同时动态填坑，双指针汇合结束
    int n = height.size();
    if (n <= 2)
        return 0;
    int ans = 0;
    int index_l = 0;
    int max_l = height[index_l];
    int index_r = n - 1;
    int max_r = height[index_r];
    //双指针的移动策略才是精髓：谁小移动谁，同时移动会有问题
    //问题的关键是，如果一侧从大变小，因为另一侧也没有兜底，你不确定这时候应该加几。如果小的那侧负责移动，可以明确就是以本侧最大值计算容量
    while (index_l < index_r) {
        if (max_l < max_r)
        {
            ans += max_l - height[index_l];//因为提前更新了自己，所以不会得到负数
            max_l = std::max(max_l, height[++index_l]);//直接把自己更新进去，下一步的公式写起来简单
        }
        else {
            ans += max_r - height[index_r];
            max_r = std::max(max_r, height[--index_r]);
        }
    }
    return ans;

}
