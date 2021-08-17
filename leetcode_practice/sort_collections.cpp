

#include "sort_collections.h"

void SortCollections::Quicksort(int array[], int L, int R) {
    if (L >= R)
        return;
    int left = L, right = R;
    int pivot = array[left];
    while (left < right)
    {
        while (left < right&&array[right] >= pivot)
            right--;
        if (left < right)//�ҵ��ˣ����һ�û���
            array[left] = array[right];//������д�룬�����������ܹ�ܴ���߽�����
        while (left < right&&array[left] <= pivot)
            left++;
        if (left < right)
            array[right] = array[left];
        if (left >= right)
            array[left] = pivot;
    }
    Quicksort(array, L, right - 1);
    Quicksort(array, right + 1, R);




    /*
    //��ֹ�������ж�
    if (L >= R)
        return;

    int pointer_l = L;
    int pointer_r = R;
    int pivot = array[pointer_l];//���������ࣩ��һ��pivot������L��R�Ѿ��ֱ�ָ��������������±���
    
    //ʹ��˫ָ������������Ƚϣ������𽥻���
    bool is_left_turn=false;
    while (pointer_l < pointer_r) {
        //һ��ֻ�ƶ�һ���±꣬��LR�����ƶ���������ֹ��ҪL==R��������pivot������߼���ôд
        //����ʵ��˼·��ѭ���������������ֲ����������м��ж�һ����ֹ
        //�ڶ���˼·����һ��turn��ǣ�ȷ��ÿ��Ҫ�ƶ�L����R
        //����ǿֱ�ԵĹ̶��ֻ����Ҳ����pivot�ı���һֱ��������������С��pivot�ģ���Ϊ����ƶ�������Ҫ���Ҳ��±꣬�����ʱ�Ҳ����ݲ���Ҫ�ƶ����ͻ���ɴ������
        if (is_left_turn) {
            while (pointer_l < pointer_r&&array[pointer_l] <= pivot)
                pointer_l++;
            if (pointer_l < pointer_r) {//���ж�һ��
                array[pointer_r] = array[pointer_l];
            }
            is_left_turn = false;
        }
        else {
            while (pointer_l < pointer_r&&array[pointer_r] >= pivot)
                pointer_r--;
            if (pointer_l < pointer_r) {//���ж�һ��
                array[pointer_l] = array[pointer_r];//����ȸ�ֵ��L����ôL��߾����˸ı���
            }
            is_left_turn = true;
        }
    }
    int mid = pointer_l;
    array[mid] = pivot;//��pivot���м�

    //���������еݹ����
    Quicksort(array, L, mid - 1);
    Quicksort(array, mid+1, R);
    */

}



std::vector<int> SortCollections::sortArray_call_Quicksort(std::vector<int>& nums) {
    //int nums_array[nums.size()] = {};
    int n = nums.size();
    int *nums_array = new int[nums.size()];
    if (!nums.empty())
        memcpy(nums_array, &nums[0], nums.size() * sizeof(int));

    Quicksort(nums_array, 0, nums.size()-1);

    nums.clear();
    for (int i = 0; i < n; ++i)
    {
        nums.push_back(nums_array[i]);
    }

    return nums;

}



void SortCollections::Quicksort_regular(std::vector<int>& nums, int L, int R) {
    //��ֹ�������ж�
    if (L >= R)
        return;

    int pointer_l = L;
    int pointer_r = R;
    int pivot = nums[pointer_l];//���������ࣩ��һ��pivot������L��R�Ѿ��ֱ�ָ��������������±���

    //ʹ��˫ָ������������Ƚϣ������𽥻���
    bool is_left_turn = false;
    while (pointer_l < pointer_r) {
        //˳��������д��
        while (pointer_l < pointer_r&&nums[pointer_r] >= pivot)
            pointer_r--;
        if (pointer_l < pointer_r) {//���ж�һ��
            nums[pointer_l] = nums[pointer_r];//����ȸ�ֵ��L����ôL��߾����˸ı���
        }
        while (pointer_l < pointer_r&&nums[pointer_l] <= pivot)
            pointer_l++;
        if (pointer_l < pointer_r) {//���ж�һ��
            nums[pointer_r] = nums[pointer_l];
        }
 
    }
    int mid = pointer_l;
    nums[mid] = pivot;//��pivot���м�

    //���������еݹ����
    Quicksort_regular(nums, L, mid - 1);
    Quicksort_regular(nums, mid + 1, R);
}


//�����棺pivotѡֵ���Ż�
//���Ż�˼·��left\mid\right���㣬ȡ����ġ��е㡱��Ϊpivot����Ȼ��Ҫע���ڿӷ��Ĳ�����ʵ�ʲ���������Ƚ�������࣬ѧ���˵�һ����������
inline void swap(std::vector<int>& nums, int L, int R) {
    int tmp = nums[L];
    nums[L] = nums[R];
    nums[R] = tmp;
}
void SortCollections::Quicksort(std::vector<int>& nums, int L, int R) {
    //��ֹ�������ж�
    if (L >= R)
        return;
    int left = L;
    int right = R;

    if (right - left > 3) {//pivot��ѡȡ��Ԥ����
        int mid = (right + left) / 2;
        if (nums[left] > nums[right])//��������
            swap(nums, left, right);
        if (nums[mid] > nums[right])//��������
            swap(nums, mid, right);
        if (nums[mid] > nums[left])//��������
            swap(nums, mid, left);
    }
    int pivot = nums[left];//pivot��ѡȡ
    while (left < right) {//ʹ��˫ָ������������Ƚϣ������𽥻���
        while (left < right&&nums[right] >= pivot)//��ӷ�ע��˳��������д��
            right--;
        if (left < right) {
            nums[left] = nums[right];//����ȸ�ֵ��L����ôL��߾����˸ı���
        }
        while (left < right&&nums[left] <= pivot)
            left++;
        if (left < right) {
            nums[right] = nums[left];
        }
    }
    int mid = left;
    nums[mid] = pivot;//��pivot���м�

    //���������еݹ����
    Quicksort(nums, L, mid - 1);
    Quicksort(nums, mid + 1, R);
}



std::vector<int> SortCollections::sortArray(std::vector<int>& nums) {
#if 0
    Quicksort_regular(nums, 0, nums.size() - 1);
#else
    Quicksort(nums, 0, nums.size() - 1);
#endif
    return nums;

}