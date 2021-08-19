#include "Solution_8xx.h"





int Solution_8xx::superEggDrop(int k, int n) {
    if (k <= 0)
        return 0;
    if (k <= 1) {//少侠，忘了你只有一个蛋了？
        return n;
    }
//     if (n <= 0)
//         return 0;
    if (n == 1)//注意不是下标而是计数,边界控制不好会陷入n-mid=1-0的死循环
        return 1;
    int mid = (n+1)/2;//因为传递的是数量，不是下标，mid的计算还真是愁人，以下标的形式去使用n,(n-1)/2

    int ret1 = 0;
    int ret2 = 0;
    //left
    if (mid - 1>0) {
        ret1 = superEggDrop(k-1,mid-1);
    }
    //right
    if (n - mid>0) {
        ret2 = superEggDrop(k, n-mid);
    }



    return 1 + std::max(ret1,ret2);

}