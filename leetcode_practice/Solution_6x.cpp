#include "Solution_6x.h"



double Solution_6x::newtonSqrt(double n) {
    double x0 = n;
    while (abs(x0*x0 - n) >= 1e-6) {
         x0 = 0.5*(n / x0 + x0);
    }
    return x0;
}
