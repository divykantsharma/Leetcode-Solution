class Solution {
public:
    //SPACE OPTIMIZATION
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<int> prev(m+1,0),cur(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=j;
        for(int i=1;i<=n;i++){
            cur[0]=i;
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){     //condition of match
                    cur[j]=0+prev[j-1];
                }
                else{   //mismatch condition - min(insert,min(delete,replace))
                    cur[j]=1+min(cur[j-1],min(prev[j],prev[j-1]));    
                }
            }
            prev=cur;
        }
        return prev[m];
    }


    //TABULATION
    // int minDistance(string word1, string word2) {
    //     int n=word1.length();
    //     int m=word2.length();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    //     for(int j=0;j<=m;j++) dp[0][j]=j;
    //     for(int i=0;i<=n;i++) dp[i][0]=i;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(word1[i-1]==word2[j-1]){     //condition of match
    //                 dp[i][j]=0+dp[i-1][j-1];
    //             }
    //             else{   //mismatch condition - min(insert,min(delete,replace))
    //                 dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));    
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }


    //MEMOIZATION - with shifting of indexes
    // int f(int i,int j,string& word1,string& word2,vector<vector<int>> &dp){
    //     if(i==0) return j;     //word1 khatam hogayi , have char of word2 left to match , j+1 insertions on word1
    //     if(j==0) return i;     //i+1 deletions on word1
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i-1]==word2[j-1]){     //condition of match
    //         return dp[i][j]=0+f(i-1,j-1,word1,word2,dp);
    //     }
    //     else{   //mismatch condition - min(insert,min(delete,replace))
    //         return dp[i][j]=1+min(f(i,j-1,word1,word2,dp),min(f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));    
    //     }
    // }
    // int minDistance(string word1, string word2) {
    //     int n=word1.length();
    //     int m=word2.length();
    //     vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    //     return f(n,m,word1,word2,dp);
    // }


    //MEMOIZATION
    // int f(int i,int j,string& word1,string& word2,vector<vector<int>> &dp){
    //     if(i<0) return j+1;     //word1 khatam hogayi , have char of word2 left to match , j+1 insertions on word1
    //     if(j<0) return i+1;     //i+1 deletions on word1
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(word1[i]==word2[j]){     //condition of match
    //         return dp[i][j]=0+f(i-1,j-1,word1,word2,dp);
    //     }
    //     else{   //mismatch condition - min(insert,min(delete,replace))
    //         return dp[i][j]=1+min(f(i,j-1,word1,word2,dp),min(f(i-1,j,word1,word2,dp),f(i-1,j-1,word1,word2,dp)));    
    //     }
    // }
    // int minDistance(string word1, string word2) {
    //     int n=word1.length();
    //     int m=word2.length();
    //     vector<vector<int>> dp(n,vector<int>(m,-1));
    //     return f(n-1,m-1,word1,word2,dp);
    // }


    //RECURSION - TLE
    // int f(int i,int j,string& word1,string& word2){
    //     if(i<0) return j+1;     //word1 khatam hogayi , have char of word2 left to match , j+1 insertions on word1
    //     if(j<0) return i+1;     //i+1 deletions on word1
    //     if(word1[i]==word2[j]){     //condition of match
    //         return 0+f(i-1,j-1,word1,word2);
    //     }
    //     else{   //mismatch condition - min(insert,min(delete,replace))
    //         return 1+min(f(i,j-1,word1,word2),min(f(i-1,j,word1,word2),f(i-1,j-1,word1,word2)));    
    //     }
    // }
    // int minDistance(string word1, string word2) {
    //     int n=word1.length();
    //     int m=word2.length();
    //     return f(n-1,m-1,word1,word2);
    // }
};