class Solution {
public:
    //TABULATION
    int numSquares(int n){
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int ans=1e9;
            for(int j=1;j<=sqrt(n);j++){
                int temp=j*j;
                if(i-temp>=0) ans=min(ans,1+dp[i-temp]);
            }
            dp[i]=ans;
        }
        return dp[n];
    }


    //MEMOIZATION
    // int f(int n,vector<int>& dp){
    //     if(n==0) return 0;
    //     if(dp[n]!=-1) return dp[n];
    //     int ans=1e9;
    //     for(int i=1;i<=sqrt(n);i++){
    //         int temp=i*i;
    //         ans=min(ans,1+f(n-temp,dp));
    //     }
    //     return dp[n]=ans;
    // }
    // int numSquares(int n){
    //     vector<int> dp(n+1,-1);
    //     return f(n,dp);
    // }


    //RECURSION - TLE
    // int f(int n){
    //     if(n==0) return 0;
    //     int ans=1e9;
    //     for(int i=1;i<=sqrt(n);i++){
    //         ans=min(ans,1+f(n-(i*i)));
    //     }
    //     return ans;
    // }
    // int numSquares(int n){
    //     return f(n);
    // }
};