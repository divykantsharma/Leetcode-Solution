class Solution {
public:
    //TABULATION
    int minDistance(string word1, string word2){
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);         
            }
        }
        int len=dp[n][m];  //length of LCS
        return m+n-2*(len);
    }

    
    //MEMOIZATION
    // int f(int i,int j,string &word1,string &word2,vector<vector<int>>& dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i]==word2[j]) return dp[i][j]=1+f(i-1,j-1,word1,word2,dp);
    //     else{
    //         return dp[i][j]=max(f(i-1,j,word1,word2,dp),f(i,j-1,word1,word2,dp));
    //     }
    // }
    // int minDistance(string word1, string word2){
    //     int n=word1.length();
    //     int m=word2.length();
    //     vector<vector<int>> dp(n,vector<int> (m,-1));
    //     int len=f(n-1,m-1,word1,word2,dp);  //length of LCS
    //     return m+n-2*(len);
    // }
};