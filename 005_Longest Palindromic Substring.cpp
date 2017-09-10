
class Solution {
public:
    string longestPalindrome(string s) {
        char *str=new char[s.size()*2+1];
        for (int i=0; i<s.size()*2+1; i++){
            if (i%2==0){
                str[i]=' ';
            }
            else str[i]=s[i/2];
        }
        int *R=new int[s.size()*2+1];
        int flag=0;
        int left=0, right=0;
        int n=s.size()*2+1;
        int maxR=0;
        int head=0, maxL=0;
        while(flag<n){
            if (n-flag<=maxR) break;
            while(left>=0 && right<n && str[left]==str[right]){
                left--;
                right++;
            }
            left++;
            right--;
            R[flag]=right-flag;
            if (R[flag]>maxR) {
                maxR=R[flag];
                int tail=(right-1)/2;
                head=left/2;
                maxL=tail-head+1;
            }
            
            if (flag==right){
                flag=right=left=flag+1;
            }
            else
                for (int i=flag+1; i<=right; i++){
                    int j=2*flag-i;
                    if (R[j]>=right-i){
                        flag=i;
                        right++;
                        left=2*i-right;
                        break;
                    }
                    else {
                        R[i]=R[j];
                    }
                }
        }
        delete []R;
        delete []str;
        return s.substr(head, maxL);
    }
};
