
#include "solution_0x.h"

std::vector<int> Solution_0x::twoSum(std::vector<int>& nums, int target) {
    std::vector<int> two_index;
    //ʹ�ù�ϣ�����
    std::map<int, int> dictionary;
    for (int i = 0; i < nums.size(); ++i) {
        int find_key = target - nums[i];
        if (dictionary.count(find_key)>0) {//dictionary[cur] != 0 �±���0��������������ж�  &&  dictionary[cur]�Զ����ʲ�д��k-v
            two_index.push_back(dictionary[find_key]);
            two_index.push_back(i);
            return two_index;
        }
        dictionary[nums[i]] = i;
    }
    return two_index;
}

std::vector<int> Solution_0x::twoSum_brute(std::vector<int>& nums, int target) {
    std::vector<int> two_index;
    //������
    //���˱߽����֮��ģ�û����������
    //��ǰ����92.34%

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                two_index.push_back(i);
                two_index.push_back(j);
                return two_index;
            }

        }
    }
    return two_index;
}

#include "Solution_0x.h"




std::vector<int> Solution_0x::twoSum_2points(std::vector<int>& nums, int target) {

    std::vector<int> two_index;
    return two_index;
#if 0
    //����˫ָ�뷨
    //����ָ��ͬʱ���м��ƶ���������
    //�뱩����ͬʱ�ύ������

    //��Ҫ�������򣬲���֤����,�����Ժ󣬷��ص�index�����ˣ��������˫ָ��Ҫ�ض��������飬�Լ�sort��Ҫ�Լ���ס��Ӧ��ϵ��

    std::sort(nums.begin(), nums.end());

    std::vector<int> two_index;
    int sum = 0;
    int i = 0, j = nums.size() - 1;
    sum = nums[i] + nums[j];
    while (sum != target) {
        if (sum < target) {
            if (nums[i + 1] + nums[j] > target)
                j--;
            else
                i++;
        }
        else {

            if (nums[i] + nums[j - 1] < target)
                i++;
            else
                j--;
            ;
        }
        sum = nums[i] + nums[j];
    }
    two_index.push_back(i);
    two_index.push_back(j);
    return two_index;
#endif
}


ListNode* Solution_0x::addTwoNumbers(ListNode* l1, ListNode* l2) {


    /*
    *�����ˣ���Ϊ�����Ե�ʣ���ʵͷ��������һλ���򵥵����ͺã�ƿ���Ǵ洢λ������ǰ���������û�����⣨����д���Ѷ���
    unsigned long long num1 = 0,num2=0,sum=0;
    //�����������
    //�ڵ�2  4  3��Ӧ����342
    int i = 0,j=0;
    while (l1 != NULL) {
    num1 += l1->val * pow(10,i++);
    l1 = l1->next;
    }
    while (l2 != NULL) {
    num2 += l2->val * pow(10,j++);
    l2 = l2->next;
    }
    sum = num1 + num2;

    ListNode*ret = new ListNode();
    ListNode*cur = ret;
    while (sum) {
    cur->val = sum%10;
    sum /= 10;
    if (!sum) {
    return ret;
    }
    ListNode*tmp = new ListNode();
    cur->next = tmp;
    cur = tmp;

    }

    return ret;
    */
    return NULL;
}







