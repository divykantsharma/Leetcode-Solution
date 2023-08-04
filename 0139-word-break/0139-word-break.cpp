class Solution {
public:
    //MEMOIZATION
    bool f(int pos,string& s,unordered_set<string>& st,vector<int>& dp){
        if(pos==s.size()) return true;
        if(dp[pos]!=-1) return dp[pos];
        for(int i=pos;i<s.size();i++){
            if(st.find(s.substr(pos,i-pos+1))!=st.end() && f(i+1,s,st,dp)){
                return dp[pos]=true;
            }
        }
        return dp[pos]=false;
    }
    bool wordBreak(string s,vector<string>& wordDict){
        int n=s.size();
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(n,-1);
        return f(0,s,st,dp);
    }


    //RECURSION - TLE - (35/46) testcases passed
    // bool f(int pos,string& s,unordered_set<string>& st){
    //     if(pos==s.size()) return true;
    //     for(int i=pos;i<s.size();i++){
    //         if(st.find(s.substr(pos,i-pos+1))!=st.end() && f(i+1,s,st)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // bool wordBreak(string s,vector<string>& wordDict){
    //     unordered_set<string> st(wordDict.begin(), wordDict.end());
    //     return f(0,s,st,dp);
    // }
};