int MOD=(int)(1e9+7);
class Solution {
public:
    //TABULATION
    int numTilings(int n){
        vector<long long int> dp(n+1,0);
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;  
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;  
        for(int i=4;i<=n;i++){
            dp[i]=(2*(dp[i-1])%MOD+(dp[i-3])%MOD)%MOD;
        }
        return dp[n];
    }


    //MEMOIZATION
    // int f(int n,vector<int>& dp){
    //     if(n==0) dp[0]=0;
    //     if(n==1) dp[1]=1;
    //     if(n==2) dp[2]=2;
    //     if(n==3) dp[3]=5;
    //     if(dp[n]!=-1) return dp[n];
    //     return dp[n]=(2*(f(n-1,dp))%MOD+(f(n-3,dp))%MOD)%MOD;
    // }
    // int numTilings(int n){
    //     vector<int> dp(n+1,-1);
    //     return f(n,dp);
    // }


    //RECURSION - OVERLAPPING SUBPROBLEMS (TLE)
    // int numTilings(int n){
    //     if(n<=2) return n;
    //     if(n==3) return 5;
    //     return (2*(numTilings(n-1))%MOD+(numTilings(n-3))%MOD)%MOD;
    // }
};