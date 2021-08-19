
#include "Solution_11xx.h"


int Solution_11xx::tribonacci(int n) {
    if (n < 2)
        return n;
    if (n == 2)
        return 1;

    int p = 0, q = 0, r = 1, s = 1;
    for (int i = 3; i <= n; ++i) {
        p = q;
        q = r;
        r = s;
        s = p + q + r;
    }
    return s;
}
