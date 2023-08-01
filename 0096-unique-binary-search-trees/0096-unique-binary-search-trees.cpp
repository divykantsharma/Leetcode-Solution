class Solution {
public:
    //CATALAN NUMBER SERIES - 1,2,5,14,42,132,429,1430,...,1767263190(for 19) - TLE dega as fact(2*n)
    //expression - (2n)!/(n+1)!*n!
    // long long int factorial(int n){
    //     if(n==0 || n==1) return 1;
    //     return n*factorial(n-1);
    // }
    // int numTrees(int n){
    //     return (factorial(2*n))/(factorial(n+1)*factorial(n)); 
    // }


    //MEMOIZATION
    int f(int n,vector<int>& dp){
        if(n==0 ||n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int result=0;
        for(int i=1;i<=n;i++){
            result+=f(i-1,dp)*f(n-i,dp);
        }
        return dp[n]=result;   
    }
    int numTrees(int n){
        vector<int> dp(n+1,-1);
        return f(n,dp);
    }


    //TC->O(3^N)
    // int numTrees(int n){
    //     if(n==0 ||n==1) return 1;
    //     int result=0;
    //     for(int i=1;i<=n;i++){
    //         result+=numTrees(i-1)*numTrees(n-i);
    //     }
    //     return result;        
    // }
};