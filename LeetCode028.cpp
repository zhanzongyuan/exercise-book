/**
 * https://leetcode.com/problems/implement-strstr/description/
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() > haystack.size()) return -1;
        vector<int> back_match(needle.size(), 0);
        for (int i = 1; i < needle.size(); i++) {
           for (int j = 1; j <= i; j++) {
               string s1 = needle.substr(j, i-j+1);
               string s2 = needle.substr(0, i-j+1);
               if (s1 == s2) {
                   back_match[i] = i-j+1;
                   break;
               }
           }
        }
        int h = 0, iter = 0;
        while (iter < needle.size() && h < haystack.size()) {
            if (iter >= haystack.size()) return -1;
            if (haystack[h+iter] == needle[iter]) iter++;
            else if (iter == 0) {
                h++;
                iter = 0;
            }
            else {
                int match = back_match[iter-1];
                h = h + iter - match;
                iter = match;
            }
        }
        if (iter == needle.size()) return h;
        return -1;
    }
};
