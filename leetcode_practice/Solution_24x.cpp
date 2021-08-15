#include "Solution_24x.h"


bool  Solution_24x::searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int i = 0;
    int j = matrix[0].size()-1;

    while (i>=0&&i<matrix.size()&&j>=0&&j<matrix[0].size()) {
        if (matrix[i][j] < target) {
            i++;
        }
        else if (matrix[i][j] > target) {
            j--;
        }
        else {
            return true;
        }
    }
    return false;
}