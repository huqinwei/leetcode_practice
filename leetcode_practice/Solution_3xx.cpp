#include "Solution_3xx.h"



  void swap(vector<char>&s, int i, int j)
{
    int tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
void Solution_3xx::reverseString(vector<char>& s) {
    int n = s.size();
    if (n < 2)
        return;
    int i = 0, j = n - 1;
    while (i < j) {
        swap(s, i++, j--);
    }

}