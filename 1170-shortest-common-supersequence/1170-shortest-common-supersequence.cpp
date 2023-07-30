class Solution {
public:
    //TABULATION
    // string shortestCommonSupersequence(string str1, string str2){
    //     int n=str1.length(); //TABULATION code of LCS which contains the lengths in dp table 
    //     int m=str2.length();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //     for(int j=0;j<=m;j++) dp[0][j]=0;
    //     for(int i=0;i<=n;i++) dp[i][0]=0;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
    //             else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    //         }
    //     }
    //     string ans="";
    //     int i=n,j=m;
    //     while(i>0 && j>0){
    //         if(str1[i-1]==str2[j-1]){
    //             ans+=str1[i-1];
    //             i--;
    //             j--;
    //         }
    //         else if(dp[i-1][j]>dp[i][j-1]){
    //             ans+=str1[i-1];
    //             i--;
    //         }
    //         else{
    //             ans+=str2[j-1];
    //             j--;
    //         }
    //     }
    //     while(i>0){
    //         ans+=str1[i-1];
    //         i--;
    //     }
    //     while(j>0){
    //         ans+=str2[j-1];
    //         j--;
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }


// MEMOIZATION - SHIFTING OF INDEXES IS DONE FOR TABULATION
    int f(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(i==0 || j==0) return 0;      //Base Case
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]){      
            return dp[i][j]=1+f(i-1,j-1,s,t,dp);
        }
        return dp[i][j]=max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));  
    }
    string shortestCommonSupersequence(string str1,string str2){
        int n=str1.length();   
        int m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int len=f(n,m,str1,str2,dp);
        string ans="";
        int i=n,j=m;
        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+=str1[i-1];
                i--;
            }
            else{
                ans+=str2[j-1];
                j--;
            }
        }
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans+=str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};