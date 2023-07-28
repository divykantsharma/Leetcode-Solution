class Solution {
public:
    //SPACE OPTIMIZATION
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> prev(amount+1,0),cur(amount+1,0);
        for(int T=0;T<=amount;T++){
            prev[T]=(T%coins[0]==0);
        }
        for(int ind=1;ind<n;ind++){
            for(int T=0;T<=amount;T++){
                int nottake=prev[T];
                int take=0;
                if(coins[ind]<=T) take=cur[T-coins[ind]];
                cur[T]=take+nottake;
            }
            prev=cur;
        }
        return prev[amount];
    }


    //TABULATION
    // int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,0));
    //     for(int T=0;T<=amount;T++){
    //         dp[0][T]=(T%coins[0]==0);
    //     }
    //     for(int ind=1;ind<n;ind++){
    //         for(int T=0;T<=amount;T++){
    //             int nottake=dp[ind-1][T];
    //             int take=0;
    //             if(coins[ind]<=T) take=dp[ind][T-coins[ind]];
    //             dp[ind][T]=take+nottake;
    //         }
    //     }
    //     return dp[n-1][amount];
    // }


    //MEMOIZATION
    // int f(int ind,int T,vector<int>& coins,vector<vector<int>>& dp){
    //     if(ind==0) return (T%coins[0]==0);
    //     if(dp[ind][T]!=-1) return dp[ind][T];
    //     int nottake=f(ind-1,T,coins,dp);
    //     int take=0;
    //     if(coins[ind]<=T) take=f(ind,T-coins[ind],coins,dp);
    //     return dp[ind][T]=take+nottake;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //     vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    //     return f(n-1,amount,coins,dp);
    // }


    //RECURSION - TLE
    // int f(int ind,int T,vector<int>& coins){
    //     if(ind==0){
    //         return (T%coins[0]==0);
    //     }
    //     int nottake=f(ind-1,T,coins);
    //     int take=0;
    //     if(coins[ind]<=T) take=f(ind,T-coins[ind],coins);
    //     return take+nottake;
    // }
    // int change(int amount, vector<int>& coins) {
    //     int n=coins.size();
    //     return f(n-1,amount,coins);
    // }
};