#include "Solution_8xx.h"





int Solution_8xx::superEggDrop(int k, int n) {
    if (k <= 0)
        return 0;
    if (k <= 1) {//������������ֻ��һ�����ˣ�
        return n;
    }
//     if (n <= 0)
//         return 0;
    if (n == 1)//ע�ⲻ���±���Ǽ���,�߽���Ʋ��û�����n-mid=1-0����ѭ��
        return 1;
    int mid = (n+1)/2;//��Ϊ���ݵ��������������±꣬mid�ļ��㻹���ǳ��ˣ����±����ʽȥʹ��n,(n-1)/2

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