class Solution {
public:
    //SPACE OPTIMIZATION
    int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<int> prev(n,0);
        for(int j=0;j<n;j++){
            prev[j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> cur(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+prev[j];
                int digonal=triangle[i][j]+prev[j+1];
                cur[j]=min(down,digonal);
            }
            prev=cur;
        }
        return prev[0];
    }


    //TABULATION   -   TC:O(nxn) , SC:O(nxn)
    // int minimumTotal(vector<vector<int>>& triangle){
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     for(int j=0;j<n;j++){
    //         dp[n-1][j]=triangle[n-1][j];
    //     }
    //     for(int i=n-2;i>=0;i--){
    //         for(int j=i;j>=0;j--){
    //             int down=triangle[i][j]+dp[i+1][j];
    //             int digonal=triangle[i][j]+dp[i+1][j+1];
    //             dp[i][j]=min(down,digonal);
    //         }
    //     }
    //     return dp[0][0];
    // }


    //MEMOIZATION   -   TC:O(nxn) , SC:O(nxn)+O(n)
    // int f(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
    //     if(i==n-1) return triangle[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int down=triangle[i][j]+f(i+1,j,n,triangle,dp);
    //     int digonal=triangle[i][j]+f(i+1,j+1,n,triangle,dp);
    //     return dp[i][j]=min(down,digonal);
    // }
    // int minimumTotal(vector<vector<int>>& triangle){
    //     int n=triangle.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     return f(0,0,n,triangle,dp);
    // }


    //RECURSION - TLE   -   TC:O(2^(1+2+3...+n)) , SC:O(n)
    // int f(int i,int j,int n,vector<vector<int>>& triangle){
    //     if(i==n-1) return triangle[i][j];
    //     int down=triangle[i][j]+f(i+1,j,n,triangle);
    //     int digonal=triangle[i][j]+f(i+1,j+1,n,triangle);
    //     return min(down,digonal);
    // }
    // int minimumTotal(vector<vector<int>>& triangle){
    //     int n=triangle.size();
    //     return f(0,0,n,triangle);
    // }
};