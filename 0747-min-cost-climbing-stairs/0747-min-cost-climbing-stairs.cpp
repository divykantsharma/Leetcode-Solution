class Solution {
public:
    //TABULATION
    int minCostClimbingStairs(vector<int>& cost){
        int n=cost.size();
        vector<int> dp(n,0);
        dp[n-1]=cost[n-1];
        dp[n-2]=cost[n-2];
        for(int ind=n-3;ind>=0;ind--){
            int small=cost[ind]+dp[ind+1];
            int large=INT_MAX;
            if(ind<n-2) large=cost[ind]+dp[ind+2];
            dp[ind]=min(small,large);
        }
        int ans1=dp[0];
        int ans2=dp[1];
        return min(ans1,ans2);
    }


    //MEMOIZATION
    //     int f(int ind,vector<int>& cost,vector<int>& dp){
    //     int n=cost.size();
    //     if(ind==n-1) return cost[n-1];
    //     if(ind==n-2) return cost[n-2];
    //     if(dp[ind]!=-1) return dp[ind];
    //     int small=cost[ind]+f(ind+1,cost,dp);
    //     int large=INT_MAX;
    //     if(ind<n-2) large=cost[ind]+f(ind+2,cost,dp);
    //     return dp[ind]=min(small,large);
    // }
    // int minCostClimbingStairs(vector<int>& cost){
    //     int n=cost.size();
    //     vector<int> dp(n,-1);
    //     int ans1=f(0,cost,dp);
    //     int ans2=f(1,cost,dp);
    //     return min(ans1,ans2);
    // }


    //RECURSION - TLE
    // int f(int ind,vector<int>& cost){
    //     int n=cost.size();
    //     if(ind==n-1) return cost[n-1];
    //     if(ind==n-2) return cost[n-2];
    //     int small=cost[ind]+f(ind+1,cost);
    //     int large=INT_MAX;
    //     if(ind<n-2) large=cost[ind]+f(ind+2,cost);
    //     return min(small,large);
    // }
    // int minCostClimbingStairs(vector<int>& cost){
    //     int ans1=f(0,cost);
    //     int ans2=f(1,cost);
    //     return min(ans1,ans2);
    // }
};