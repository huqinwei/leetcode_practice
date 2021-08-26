#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"

///所有1100-1199题


class Solution_11xx {
public:

    //1137 tribonacci  第 N 个泰波那契数
    //DP
    int Solution_11xx::tribonacci(int n);




    //迭代过程
    void count_path_recursion(int target, int& global_min_value, int next_push_idx, int total_value, unordered_set<int> current_path, unordered_map<int, vector<pair<int, int>>> &path_dict, unordered_map<int, int> &res_map, vector<int>& dp, vector<int>& dp_initialized) {
        //当前路径串的数据结构，带顺序吗？还是带着集合本身就行了，只要避免回环就行
        //当前的尾部，查dict，所有指向都遍历一下，不重复则插入，再迭代
        //当前串用set存储，再往下穿一个当前value总和，
        //最后return回来，取所有结果的min，向上返回
        if (total_value > global_min_value)//提前中断，即使是提前中断，DFS还是太慢了。
            return;
        if (!dp_initialized[next_push_idx])
        {
            dp[next_push_idx] = total_value;
            dp_initialized[next_push_idx] = 1;//初始化
        }
        else {
            //中途点判断，如果非最优，返回，但是不能截住其他已经跳过这个中途点的路径
            //除非：每一个路径更新过程中还把自己旧的全部路径和dp对比一下，同idx的value大过dp，当前路径直接取消掉？
            if (total_value > dp[next_push_idx])
                return;

            dp[next_push_idx] = min(dp[next_push_idx], total_value);//更新最优
        }


        current_path.insert(next_push_idx);
        int current_idx = next_push_idx;
        vector<pair<int, int>> &ret = path_dict[current_idx];
        //int min_value = INT_MAX;
        for (int i = 0; i < ret.size(); ++i) {//因为循环很多次，total_value不要乱篡改
            int next_idx = ret[i].first;
            int value = ret[i].second;
            if (current_path.find(next_idx) == current_path.end()) {
                if (next_idx == target) {
                    res_map[total_value + value] += 1;
                    global_min_value = min(global_min_value, total_value + value);
                    continue;
                }
                else {
                    count_path_recursion(target, global_min_value, next_idx, total_value + value, current_path, path_dict, res_map, dp, dp_initialized);
                }
            }
            else {
                continue;
            }
        }
    }
    //5836：最终的思路是BFS+DP，并且动态更新DP，记录每个index下的最小value，超过的都直接中断，但是只是思路，别人是dijkstra+dp
    int countPaths(int n, vector<vector<int>>& roads) {
        //建立映射关系
        //我被题意坑了，他说某些道路有双向，其实是所有写出来的都是双向
        //todo:正确但是超时，path的存储应该从vector转为set？


        //思路整理：无论怎么trick-break，DFS还是太慢了，有没有什么更优的方式？
        //多条路径，当有相同点的时候，还是可以直接中断掉value更大的线路的，这里边重叠度太大了
        //多条路径怎么互相查询：判断重叠的方式是尾部？中间任意一点？？保存其他路径并且供查询需要什么方法？
        //动态规划，到达任一点dp[i]，有一个最小value，每次新路径查询到这一点，如果超过这个value都没有更新的价值，如果比这小就更新dp
        //dp怎么维护？先建立所有点的dp，然后遍历到哪个点就更新哪点的dp，如果比这个大直接中断。
        unordered_set<int> point_set;


        //dp优化见效，从失败在24变为失败在29，但是没通过！！！！！！！！！




        int global_min_value = INT_MAX;//当前最低路径权重，超过的被强行中断

        unordered_map<int, vector<pair<int, int>>> path_dict;//起点，指向多个终点，每个的value
        for (int i = 0; i < roads.size(); ++i) {
            int s = roads[i][0];
            int e = roads[i][1];
            int v = roads[i][2];
            //查询，如果有这个idx，是插入
            path_dict[s].push_back({ e, v });
            path_dict[e].push_back({ s, v });//每条信息都是双向的
            point_set.insert(s);
            point_set.insert(e);
        }
        int point_set_size = point_set.size();
        vector<int> dp(point_set_size);//根据题意，直接=n也行
        vector<int> dp_initialized(point_set_size);//dp是否被初始化？没有的话需要初始化一次

                                                   //n是target，需要，如果当前刚好是7，return
        unordered_set<int> current_path;//unordered_set

        unordered_map<int, int> res_map;//前者是路径value，后者是有多少条是这个value,统计
                                        //最后需要遍历，找到最小的路径，返回统计值


                                        //int ret = 
        count_path_recursion(n - 1, global_min_value, 0, 0, current_path, path_dict, res_map, dp, dp_initialized);
        int min_value = INT_MAX;
        int path_length = 0;
        for (auto& v : res_map) {
            if (v.first < min_value) {
                min_value = v.first;
                path_length = v.second;
            }

        }
        return path_length % ((int)pow(10, 9) + 7);// ret % ((int)pow(10, 9) + 7);
    }

};
