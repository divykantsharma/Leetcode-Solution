class Solution {
public:
    //FURTHER SPACE OPTIMIZATION - 1 array is used
        int numDistinct(string s, string t){
        int n=s.length();
        int m=t.length();
        vector<double> prev(m+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){         //condtion of match 
                    prev[j]=prev[j-1]+prev[j];
                }
                else{                  //condition of mismatch
                    prev[j]=prev[j];
                }
            }
        }
        return (int)prev[m];       //typecasting of a double to integer
    }

    
    //SPACE OPTIMIZATION - 2 arrays are used
    //     int numDistinct(string s, string t){
    //     int n=s.length();
    //     int m=t.length();
    //     vector<double> prev(m+1,0),cur(m+1,0);
    //     prev[0]=cur[0]=1;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(s[i-1]==t[j-1]){         //condtion of match 
    //                 cur[j]=prev[j-1]+prev[j];
    //             }
    //             else{                  //condition of mismatch
    //                 cur[j]=prev[j];
    //             }
    //         }
    //         prev=cur;
    //     }
    //     return (int)prev[m];       //typecasting of a double to integer
    // }

    
    //TABULATION
    // int numDistinct(string s, string t){
    //     int n=s.length();
    //     int m=t.length();
    //     vector<vector<double>> dp(n+1,vector<double>(m+1,0));
    //     for(int i=0;i<=n;i++) dp[i][0]=1;
    //     for(int j=1;j<=m;j++) dp[0][j]=0;     //if we start from j=0 then dp[0][0] overwrite ho jaayega
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(s[i-1]==t[j-1]){         //condtion of match 
    //                 dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    //             }
    //             else{                  //condition of mismatch
    //                 dp[i][j]=dp[i-1][j];
    //             }
    //         }
    //     }
    //     return (int)dp[n][m];       //typecasting of a double to integer
    // }


    //UPDATED MEMOIZATION - shifting of indexes is performed
    // int f(int i,int j,string& s, string& t,vector<vector<int>>& dp){    //this will return the number of ways t appears in s
    //     if(j==0) return 1;
    //     if(i==0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i-1]==t[j-1]){         //condtion of match 
    //         return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    //     }
    //     else{                             //condition of mismatch
    //         return dp[i][j]=f(i-1,j,s,t,dp);
    //     }
    // }
    // int numDistinct(string s, string t){
    //     int n=s.length();
    //     int m=t.length();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return f(n,m,s,t,dp);
    // }


    //MEMOIZATION
    // int f(int i,int j,string& s, string& t,vector<vector<int>>& dp){    //this will return the number of ways t appears in s
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]){         //condtion of match 
    //         return dp[i][j]=f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
    //     }
    //     else{                            //condition of mismatch
    //         return dp[i][j]=f(i-1,j,s,t,dp);
    //     }
    // }
    // int numDistinct(string s, string t){
    //     int n=s.length();
    //     int m=t.length();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return f(n-1,m-1,s,t,dp);
    // }


    //RECURSION - TLE
    // int f(int i,int j,string s, string t){      //this will return the number of ways t appears in s
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(s[i]==t[j]){         //condtion of match 
    //         return f(i-1,j-1,s,t) + f(i-1,j,s,t);
    //     }
    //     else{                        //condition of mismatch
    //         return f(i-1,j,s,t);
    //     }
    // }
    // int numDistinct(string s, string t){
    //     int n=s.length();
    //     int m=t.length();
    //     return f(n-1,m-1,s,t);
    // }
};