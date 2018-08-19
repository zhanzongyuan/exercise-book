/**
 * https://leetcode.com/problems/word-search/description/
 */

vector<int> ibias = {0, 0, -1, 1};
vector<int> jbias = {-1, 1, 0, 0};

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool> > visited(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0 ; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (recur_match(board, visited, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    bool recur_match(vector<vector<char> > &board, vector<vector<bool> > &visited, int i, int j, string& word, int iter) {
        if (iter == word.size()-1 && board[i][j] == word[iter]) return true;
        if (board[i][j] != word[iter]) return false;
        visited[i][j] = true;

        for (int b = 0; b < 4; b++) {
            int ni = i + ibias[b];
            int nj = j + jbias[b];
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size() && !visited[ni][nj]) {
                if (recur_match(board, visited, ni, nj, word, iter+1) ) return true;
            }
        }

        visited[i][j] = false;
        return false;
    }
};


