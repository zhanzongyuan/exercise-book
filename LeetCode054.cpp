/**
 * 54. Spiral Matrix
 * https://leetcode.com/problems/spiral-matrix/description/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return vector<int>();
        
        vector<int> result(matrix.size()*matrix[0].size(), 0);
        vector<vector<int> > mark(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<int> yd = {0, 1, 0, -1};
        vector<int> xd = {1, 0, -1, 0};
        
        int x = 0, y = 0, ind = 0, dir=0;
        while (ind < result.size()) {
            result[ind] = matrix[y][x];
            mark[y][x] = 1;

            int nx = x+xd[dir], ny = y+yd[dir];
            if (nx < 0 || nx >= matrix[0].size() || ny < 0 || ny >= matrix.size() || mark[ny][nx] == 1) {
                dir = (dir+1)%4;
            }

            x = x+xd[dir];
            y = y+yd[dir];
            ind++;
        }
        return result;
    }
};

int main() {
    
    return 0;
}
