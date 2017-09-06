//
//  003_Longest Substring Without Repeating Characters.cpp
//  
//
//  Created by applecz on 2017/9/5.
//
//

// 3.0 v
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //这里hash_map，可以用map<char, int> hash_map;代替
        //map<char, int> hash_map;
        int hash_map[256];
        for(int i=0; i<256; i++) hash_map[i]=-1;
        int i=0, j=0, maxlen=0;
        int n=s.size();
        while(i<n && j<n){
            //map<char, int>::iterator iter=hash_map.find(s[j]);
            if (hash_map[s[j]]!=-1){
                int prej=hash_map[s[j]];
                if (prej>=i){
                    i=prej+1;
                }
            }
            //hash_map.insert(pair<char, int>(s[j], j)); map对已经存在的键自动忽略后面相同键值的插入，所以改用下标
            hash_map[s[j]]=j;
            j++;
            if (maxlen<j-i) maxlen=j-i;
        }
        return maxlen;
    }
};



/*
// 2.0 v
#include<memory.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        //维护chara只包含[i,j)内的char标记
        //维护s[i,j)是个不包含重复的字符串
        bool chara[256];
        memset(chara, 0, sizeof(chara));
        for(int i=0, j=0; j<s.size() && i<s.size(); ){
            if (chara[s[j]]) {
                //若有重复字符就继续前进i
                //直到[i, j)不再有与s[j]相同的字符
                chara[s[i]]=0;
                i++;
            }
            else{
                chara[s[j]]=1;
                j++;
                if (maxlen<j-i) maxlen=j-i;
            }
        }
        return maxlen;
    }
};
 
 
*/


/*
// 1.0 v
#include<memory.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen=0;
        for (int i=0; i<s.size(); i++){
            bool chara[256];
            memset(chara, 0, sizeof(chara));
            int len=0;
            for (int j=i; j<i+256 && j<s.size(); j++){
                if (chara[s[j]]) break;
                else {
                    chara[s[j]]=1;
                    len++;
                }
            }
            if (len>maxlen) maxlen=len;
        }
        return maxlen;
    }
};
*/
