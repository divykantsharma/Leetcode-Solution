class Solution {
public:
    bool isSubsequence(string s, string t){
        int n=s.length();
        int m=t.length();
        if(n>m) return false;
        int i=0;
        for(int j=0;j<m && i<n;j++){
            if(s[i]==t[j]) i++;
        }
        return i==n;
    }
};