class Solution {
public:
    //SPACE OPTIMIZATION - TC:O(n) , SC:O(1) - 100% BEATS on TC and 75% BEATS on SC
    int climbStairs(int n){
        int b=1;
        int c=1;
        for(int i=2;i<=n;i++){
            int a=b+c;
            c=b;
            b=a;
        }
        return b;
    }


    //TABULATION - BOTTOM UP approach - TC:O(n) , SC:O(n)-due to dp array
    // int downtop(int n,vector<int>&dp){
    //     if(n<=1) return 1;
    //     dp[0]=1;
    //     dp[1]=1;
    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }
    // int climbStairs(int n){
    //     vector<int>dp(n+1,-1);
    //     return downtop(n,dp);
    // }


    //MEMOIZATION - TOP DOWN approach - TC:O(n) , SC:O(n)+O(n)-due to recursion stack and dp array
    // int topdown(int n,vector<int>&dp){
    //     if(n<=1) return 1;          //for n==0 or n==1 return 1
    //     if(dp[n]!=-1) return dp[n];
    //     dp[n]=topdown(n-1,dp)+topdown(n-2,dp);
    //     return dp[n];
    // }
    // int climbStairs(int n){
    //     vector<int>dp(n+1,-1);
    //     return topdown(n,dp);
    // }


    //RECURSION - as n can go till 45 therefore time limit exceeds
    // int climbStairs(int n) {
    //     if(n==0) return 1;
    //     if(n==1) return 1;
    //     return climbStairs(n-1)+climbStairs(n-2);
    // }
};