#pragma once
#include <vector>
#include <algorithm>
#include "math.h"
#include <iostream>
#include <map>
#include "base.h"

///����1100-1199��


class Solution_11xx {
public:

    //1137 tribonacci  �� N ��̩��������
    //DP
    int Solution_11xx::tribonacci(int n);




    //��������
    void count_path_recursion(int target, int& global_min_value, int next_push_idx, int total_value, unordered_set<int> current_path, unordered_map<int, vector<pair<int, int>>> &path_dict, unordered_map<int, int> &res_map, vector<int>& dp, vector<int>& dp_initialized) {
        //��ǰ·���������ݽṹ����˳���𣿻��Ǵ��ż��ϱ�������ˣ�ֻҪ����ػ�����
        //��ǰ��β������dict������ָ�򶼱���һ�£����ظ�����룬�ٵ���
        //��ǰ����set�洢�������´�һ����ǰvalue�ܺͣ�
        //���return������ȡ���н����min�����Ϸ���
        if (total_value > global_min_value)//��ǰ�жϣ���ʹ����ǰ�жϣ�DFS����̫���ˡ�
            return;
        if (!dp_initialized[next_push_idx])
        {
            dp[next_push_idx] = total_value;
            dp_initialized[next_push_idx] = 1;//��ʼ��
        }
        else {
            //��;���жϣ���������ţ����أ����ǲ��ܽ�ס�����Ѿ����������;���·��
            //���ǣ�ÿһ��·�����¹����л����Լ��ɵ�ȫ��·����dp�Ա�һ�£�ͬidx��value���dp����ǰ·��ֱ��ȡ������
            if (total_value > dp[next_push_idx])
                return;

            dp[next_push_idx] = min(dp[next_push_idx], total_value);//��������
        }


        current_path.insert(next_push_idx);
        int current_idx = next_push_idx;
        vector<pair<int, int>> &ret = path_dict[current_idx];
        //int min_value = INT_MAX;
        for (int i = 0; i < ret.size(); ++i) {//��Ϊѭ���ܶ�Σ�total_value��Ҫ�Ҵ۸�
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
    //5836�����յ�˼·��BFS+DP�����Ҷ�̬����DP����¼ÿ��index�µ���Сvalue�������Ķ�ֱ���жϣ�����ֻ��˼·��������dijkstra+dp
    int countPaths(int n, vector<vector<int>>& roads) {
        //����ӳ���ϵ
        //�ұ�������ˣ���˵ĳЩ��·��˫����ʵ������д�����Ķ���˫��
        //todo:��ȷ���ǳ�ʱ��path�Ĵ洢Ӧ�ô�vectorתΪset��


        //˼·����������ôtrick-break��DFS����̫���ˣ���û��ʲô���ŵķ�ʽ��
        //����·����������ͬ���ʱ�򣬻��ǿ���ֱ���жϵ�value�������·�ģ�������ص���̫����
        //����·����ô�����ѯ���ж��ص��ķ�ʽ��β�����м�����һ�㣿����������·�����ҹ���ѯ��Ҫʲô������
        //��̬�滮��������һ��dp[i]����һ����Сvalue��ÿ����·����ѯ����һ�㣬����������value��û�и��µļ�ֵ���������С�͸���dp
        //dp��ôά�����Ƚ������е��dp��Ȼ��������ĸ���͸����ĵ��dp������������ֱ���жϡ�
        unordered_set<int> point_set;


        //dp�Ż���Ч����ʧ����24��Ϊʧ����29������ûͨ��������������������




        int global_min_value = INT_MAX;//��ǰ���·��Ȩ�أ������ı�ǿ���ж�

        unordered_map<int, vector<pair<int, int>>> path_dict;//��㣬ָ�����յ㣬ÿ����value
        for (int i = 0; i < roads.size(); ++i) {
            int s = roads[i][0];
            int e = roads[i][1];
            int v = roads[i][2];
            //��ѯ����������idx���ǲ���
            path_dict[s].push_back({ e, v });
            path_dict[e].push_back({ s, v });//ÿ����Ϣ����˫���
            point_set.insert(s);
            point_set.insert(e);
        }
        int point_set_size = point_set.size();
        vector<int> dp(point_set_size);//�������⣬ֱ��=nҲ��
        vector<int> dp_initialized(point_set_size);//dp�Ƿ񱻳�ʼ����û�еĻ���Ҫ��ʼ��һ��

                                                   //n��target����Ҫ�������ǰ�պ���7��return
        unordered_set<int> current_path;//unordered_set

        unordered_map<int, int> res_map;//ǰ����·��value���������ж����������value,ͳ��
                                        //�����Ҫ�������ҵ���С��·��������ͳ��ֵ


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
