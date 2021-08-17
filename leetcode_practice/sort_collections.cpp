

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
        if (left < right)//找到了，并且还没汇合
            array[left] = array[right];//先往左写入，所有条件就能规避错误边界条件
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
    //起止条件的判断
    if (L >= R)
        return;

    int pointer_l = L;
    int pointer_r = R;
    int pivot = array[pointer_l];//随机（从左侧）拿一个pivot，假设L和R已经分别指定好是左右起点下标了
    
    //使用双指针遍历数组做比较，左右逐渐互换
    bool is_left_turn=false;
    while (pointer_l < pointer_r) {
        //一次只移动一个下标，是LR交互移动？但是终止需要L==R，来插入pivot，这个逻辑怎么写
        //两种实现思路：循环内连续进行两种操作，但是中间判定一次终止
        //第二种思路：加一个turn标记，确定每次要移动L还是R
        //不是强直性的固定轮换，右侧大于pivot的必须一直迭代，迭代到有小于pivot的，因为左侧移动过来需要用右侧下标，如果此时右侧数据不需要移动，就会造成错误操作
        if (is_left_turn) {
            while (pointer_l < pointer_r&&array[pointer_l] <= pivot)
                pointer_l++;
            if (pointer_l < pointer_r) {//再判定一次
                array[pointer_r] = array[pointer_l];
            }
            is_left_turn = false;
        }
        else {
            while (pointer_l < pointer_r&&array[pointer_r] >= pivot)
                pointer_r--;
            if (pointer_l < pointer_r) {//再判定一次
                array[pointer_l] = array[pointer_r];//如果先赋值给L，那么L这边就用了改变后的
            }
            is_left_turn = true;
        }
    }
    int mid = pointer_l;
    array[mid] = pivot;//把pivot插中间

    //左右子序列递归调用
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
    //起止条件的判断
    if (L >= R)
        return;

    int pointer_l = L;
    int pointer_r = R;
    int pivot = nums[pointer_l];//随机（从左侧）拿一个pivot，假设L和R已经分别指定好是左右起点下标了

    //使用双指针遍历数组做比较，左右逐渐互换
    bool is_left_turn = false;
    while (pointer_l < pointer_r) {
        //顺序，先往左写入
        while (pointer_l < pointer_r&&nums[pointer_r] >= pivot)
            pointer_r--;
        if (pointer_l < pointer_r) {//再判定一次
            nums[pointer_l] = nums[pointer_r];//如果先赋值给L，那么L这边就用了改变后的
        }
        while (pointer_l < pointer_r&&nums[pointer_l] <= pivot)
            pointer_l++;
        if (pointer_l < pointer_r) {//再判定一次
            nums[pointer_r] = nums[pointer_l];
        }
 
    }
    int mid = pointer_l;
    nums[mid] = pivot;//把pivot插中间

    //左右子序列递归调用
    Quicksort_regular(nums, L, mid - 1);
    Quicksort_regular(nums, mid + 1, R);
}


//升级版：pivot选值的优化
//简单优化思路，left\mid\right三点，取三点的“中点”作为pivot，当然需要注意挖坑法的操作，实际操作最好是先交换到左侧，学别人的一个操作技巧
inline void swap(std::vector<int>& nums, int L, int R) {
    int tmp = nums[L];
    nums[L] = nums[R];
    nums[R] = tmp;
}
void SortCollections::Quicksort(std::vector<int>& nums, int L, int R) {
    //起止条件的判断
    if (L >= R)
        return;
    int left = L;
    int right = R;

    if (right - left > 3) {//pivot的选取的预处理
        int mid = (right + left) / 2;
        if (nums[left] > nums[right])//大数右移
            swap(nums, left, right);
        if (nums[mid] > nums[right])//中数右移
            swap(nums, mid, right);
        if (nums[mid] > nums[left])//中数左移
            swap(nums, mid, left);
    }
    int pivot = nums[left];//pivot的选取
    while (left < right) {//使用双指针遍历数组做比较，左右逐渐互换
        while (left < right&&nums[right] >= pivot)//填坑法注意顺序，先往左写入
            right--;
        if (left < right) {
            nums[left] = nums[right];//如果先赋值给L，那么L这边就用了改变后的
        }
        while (left < right&&nums[left] <= pivot)
            left++;
        if (left < right) {
            nums[right] = nums[left];
        }
    }
    int mid = left;
    nums[mid] = pivot;//把pivot插中间

    //左右子序列递归调用
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