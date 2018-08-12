/**
 *
 * Word Ladder II
 * https://leetcode.com/problems/word-ladder-ii/description/
 *
 */
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isNext(string a, string b) {
        int diff_num = 0;
        for (int c = 0;  c < a.size(); c++) {
            if (a[c] != b[c]) diff_num++;
        }
        return diff_num == 1;
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string > > result;
        auto iter = find(wordList.begin(), wordList.end(), endWord);
        if (iter == wordList.end()) return result;
        
        unordered_set<string> nWordList;
        for (string s : wordList) nWordList.insert(s);
        
        queue<vector<string> > paths; 
        paths.push({beginWord});

        unordered_set<string> next_pace;
        int limit_pace_num = -1;
        while (!paths.empty()) {
            int cur_path_num = paths.size();
            // Processing the path with the same pace number.
            for (int i = 0; i < cur_path_num; i++) {
                vector<string> top_path = paths.front();
                paths.pop();
                string end_pace = top_path.back();

                if (end_pace == endWord) {
                    result.push_back(top_path);
                    if (limit_pace_num == -1 || limit_pace_num > top_path.size()) {
                        limit_pace_num = top_path.size();
                    }
                }
                else if (limit_pace_num == -1 || limit_pace_num > top_path.size()) {
                    for (char j = 0; j < end_pace.size(); j++)
                        for (char c = 'a'; c <= 'z'; c++) {
                            if (c != end_pace[j]) {
                                string s = end_pace;
                                s[j] = c;
                                if (nWordList.find(s) != nWordList.end()) {
                                    vector<string> temp = top_path;
                                    temp.push_back(s);
                                    paths.push(temp);
                                    next_pace.insert(s);
                                }
                            }
                        }
                }
                else if (limit_pace_num != -1 && limit_pace_num < top_path.size()) {
                    break;
                }
                
            }
            for (string s : next_pace) {
                auto iter = nWordList.find(s);
                if (iter != nWordList.end()) {
                    nWordList.erase(iter);
                }
            }
            next_pace.clear();
        }

        return result;
    }
};

void mprint(vector<vector<string> > list) {
    for (int l = 0; l < list.size(); l++) {
        for (int s = 0; s < list[0].size(); s++) {
            cout<<list[l][s]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    string begin = "qa";
    string end = "sq";
    vector<string> list = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
    Solution s;
    mprint(s.findLadders(begin, end, list));
    return 0;
}
