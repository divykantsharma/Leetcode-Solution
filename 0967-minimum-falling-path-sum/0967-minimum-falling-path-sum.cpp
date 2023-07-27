class Solution {
public:
    //TABULATION
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int mini=INT_MAX;
                mini=min(mini,matrix[i][j]+dp[i-1][j]);
                if(j>=1) mini=min(mini,matrix[i][j]+dp[i-1][j-1]);
                if(j<n-1) mini=min(mini,matrix[i][j]+dp[i-1][j+1]);
                dp[i][j]=mini;
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<n;j++){
            ans=min(ans,dp[n-1][j]);
        }
        return ans;
    }


    //MEMOIZATION - TLE (49/50 test cases run) 
    // int f(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
    //     int n=matrix.size();
    //     if(j<0 || j>=n) return 1e9;
    //     if(i==0) return matrix[0][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int straight=matrix[i][j]+f(i-1,j,matrix,dp);
    //     int leftdiagonal=matrix[i][j]+f(i-1,j-1,matrix,dp);
    //     int rightdiagonal=matrix[i][j]+f(i-1,j+1,matrix,dp);
    //     return dp[i][j]=min(straight,min(leftdiagonal,rightdiagonal));
    // }  
    // int minFallingPathSum(vector<vector<int>>& matrix){
    //     int n=matrix.size();
    //     int mini=1e9;
    //     vector<vector<int>> dp(n,vector<int> (n,-1));
    //     for(int j=0;j<n;j++){
    //         int ans=f(n-1,j,matrix,dp);
    //         mini=min(ans,mini);
    //     }
    //     return mini;
    // }


    //RECURSION - TLE (38/50 test cases run) 
    // int f(int i,int j,vector<vector<int>>& matrix){
    //     int n=matrix.size();
    //     if(j<0 || j>=n) return 1e9;
    //     if(i==0) return matrix[0][j];
    //     int straight=matrix[i][j]+f(i-1,j,matrix);
    //     int leftdiagonal=matrix[i][j]+f(i-1,j-1,matrix);
    //     int rightdiagonal=matrix[i][j]+f(i-1,j+1,matrix);
    //     return min(straight,min(leftdiagonal,rightdiagonal));
    // }  
    // int minFallingPathSum(vector<vector<int>>& matrix){
    //     int n=matrix.size();
    //     int mini=INT_MAX;
    //     for(int j=0;j<n;j++){
    //         int ans=f(n-1,j,matrix);
    //         mini=min(ans,mini);
    //     }
    //     return mini;
    // }
};