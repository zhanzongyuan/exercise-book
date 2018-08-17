/**
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int max_a = 0;
        for (int i = 0; i < heights.size(); i++) {
            int len = 1;
            int l = i-1, r = i+1;
            while(l >= 0 && heights[l] >= heights[i]) {
                len++;
                l--;
            }
            while(r < heights.size() && heights[r] >= heights[i]) {
                len++;
                r++;
            }
            int area = heights[i]*len;
            if (area > max_a) max_a = area;
        }
        return max_a;
    }
};
