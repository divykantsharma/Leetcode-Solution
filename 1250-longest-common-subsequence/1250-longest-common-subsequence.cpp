class Solution {
public:
    //SPACE OPTIMIZATION
    int longestCommonSubsequence(string text1,string text2){
        int n=text1.length();
        int m=text2.length();
        vector<int> prev(m+1,0),cur(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        return prev[m];
    }


    //TABULATION
    // int longestCommonSubsequence(string text1,string text2){
    //     int n=text1.length();
    //     int m=text2.length();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //     for(int j=0;j<=m;j++) dp[0][j]=0;
    //     for(int i=0;i<=n;i++) dp[i][0]=0;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
    //             else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    //     return dp[n][m];
    // }


    //MEMOIZATION - if strings are not passed by refrence in f, TLE occurs - SHIFTING OF INDEXES IS DONE FOR TABULATION 
    // int f(int i,int j,string& text1,string& text2,vector<vector<int>>& dp){
    //     if(i==0 || j==0) return 0;      //Base Case
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i-1]==text2[j-1]){      //condition where index value matches
    //         return dp[i][j]=1+f(i-1,j-1,text1,text2,dp);
    //     }
    //     return dp[i][j]=max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));  //not match
    // }
    // int longestCommonSubsequence(string text1,string text2){
    //     int n=text1.length();
    //     int m=text2.length();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return f(n,m,text1,text2,dp);
    // }


    //RECURSION - TLE
    // int f(int i,int j,string text1,string text2){
    //     if(i<0 || j<0) return 0;      //Base Case
    //     if(text1[i]==text2[j]){      //condition where index value matches
    //         return 1+f(i-1,j-1,text1,text2);
    //     }
    //     return max(f(i-1,j,text1,text2),f(i,j-1,text1,text2));  //not match
    // }
    // int longestCommonSubsequence(string text1,string text2){
    //     int n=text1.length();
    //     int m=text2.length();
    //     return f(n-1,m-1,text1,text2);
    // }
};