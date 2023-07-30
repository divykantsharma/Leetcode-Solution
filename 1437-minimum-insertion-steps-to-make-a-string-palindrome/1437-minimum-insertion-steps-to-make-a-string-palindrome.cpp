class Solution {
public:
    //SPACE OPTIMIZATION
    int minInsertions(string s){
        int n=s.length();
        string s1=s;
        reverse(s1.begin(),s1.end());
        vector<int> prev(n+1,0),cur(n+1,0);
        for(int j=0;j<=n;j++) prev[j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s1[j-1]) cur[j]=1+prev[j-1];
                else cur[j]=max(prev[j],cur[j-1]);
            }
            prev=cur;
        }
        int lps=prev[n];       //returns the length of longest palindromic subsequence
        return n-lps;
    }


    //TABULATION
    // int minInsertions(string s){
    //     int n=s.length();
    //     string s1=s;
    //     reverse(s1.begin(),s1.end());
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //     for(int j=0;j<=n;j++) dp[0][j]=0;
    //     for(int i=0;i<=n;i++) dp[i][0]=0;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=n;j++){
    //             if(s[i-1]==s1[j-1]) dp[i][j]=1+dp[i-1][j-1];
    //             else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    //     int lps=dp[n][n];       //returns the length of longest palindromic subsequence
    //     return n-lps;
    // }


    //MEMOIZATION - if strings are not passed by refrence in f, TLE occurs - SHIFTING OF INDEXES IS DONE FOR TABULATION 
    // int f(int i,int j,string& text1,string& text2,vector<vector<int>>& dp){
    //     if(i==0 || j==0) return 0;      //Base Case
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(text1[i-1]==text2[j-1]){      //condition where index value matches
    //         return 1+f(i-1,j-1,text1,text2,dp);
    //     }
    //     return dp[i][j]=max(f(i-1,j,text1,text2,dp),f(i,j-1,text1,text2,dp));  //not match
    // }
    // int minInsertions(string s){
    //     int n=s.length();
    //     string s1=s;
    //     reverse(s1.begin(),s1.end());
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    //     int lps=f(n,n,s,s1,dp);       //returns the length of longest palindromic subsequence
    //     return n-lps;
    // }


    //RECURSION - Memory Limit Exceeded
    // int f(int i,int j,string text1,string text2){
    //     if(i<0 || j<0) return 0;      //Base Case
    //     if(text1[i]==text2[j]){      //condition where index value matches
    //         return 1+f(i-1,j-1,text1,text2);
    //     }
    //     return max(f(i-1,j,text1,text2),f(i,j-1,text1,text2));  //not match
    // }
    // int minInsertions(string s){
    //     int n=s.length();
    //     string s1=s;
    //     reverse(s1.begin(),s1.end());       
    //     int lps=f(n-1,n-1,s,s1);         //returns the length of longest palindromic subsequence
    //     return n-lps;
    // }
};







