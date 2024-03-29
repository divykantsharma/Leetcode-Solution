class Solution {
public:
    //FURTHER COMPLEXITY REDUCTION
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        vector<int> front2(2,0),front1(2,0),curr(2,0);
        for(int index=n-1;index>=0;index--){
            curr[1]=max(-prices[index]+front1[0],0+front1[1]);
            curr[0]=max(prices[index]+front2[1],0+front1[0]);
            front2=front1;
            front1=curr;
        }
        return curr[1];    //as hum n-1 se 0 par jaa rahe hei toh answer will be stored in 0 only 
    }


    //COMPLEXITY REDUCTION
    // int maxProfit(vector<int>& prices) {
    //     int profit=0;
    //     int n=prices.size();
    //     vector<vector<int>> dp(n+2,vector<int> (2,0));
    //     for(int index=n-1;index>=0;index--){
    //         dp[index][1]=max(-prices[index]+dp[index+1][0],0+dp[index+1][1]);
    //         dp[index][0]=max(prices[index]+dp[index+2][1],0+dp[index+1][0]);
    //     }
    //     return dp[0][1];    //as hum n-1 se 0 par jaa rahe hei toh answer will be stored in 0 only 
    // }


    //TABULATION
    // int maxProfit(vector<int>& prices) {
    //     int profit=0;
    //     int n=prices.size();
    //     vector<vector<int>> dp(n+2,vector<int> (2,0));
    //     for(int index=n-1;index>=0;index--){
    //         for(int buy=1;buy>=0;buy--){
    //             if(buy){
    //                 profit=max(-prices[index]+dp[index+1][0],0+dp[index+1][1]);
    //             }
    //             else{
    //                 profit=max(prices[index]+dp[index+2][1],0+dp[index+1][0]);
    //             }
    //             dp[index][buy]=profit;
    //         }
    //     }
    //     return dp[0][1];    //as hum n-1 se 0 par jaa rahe hei toh answer will be stored in 0 only 
    // }


    //MEMOIZATION
    // int f(int index,int buy,vector<int>& prices,vector<vector<int>>& dp){
    //     int profit=0;
    //     int n=prices.size();
    //     //Base Case
    //     if(index>=n) return 0;
    //     if(dp[index][buy]!=-1) return dp[index][buy];
    //     if(buy){
    //         profit=max(-prices[index]+f(index+1,0,prices,dp),0+f(index+1,1,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[index]+f(index+2,1,prices,dp),0+f(index+1,0,prices,dp));
    //     }
    //     return dp[index][buy]=profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<int>> dp(n,vector<int> (2,-1));
    //     return f(0,1,prices,dp);
    // }


    //RECURSION - TLE
    // int f(int index,int buy,vector<int>& prices){
    //     int profit=0;
    //     int n=prices.size();
    //     //Base Case
    //     if(index>=n) return 0;
    //     if(buy){
    //         profit=max(-prices[index]+f(index+1,0,prices),0+f(index+1,1,prices));
    //     }
    //     else{
    //         profit=max(prices[index]+f(index+2,1,prices),0+f(index+1,0,prices));
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     return f(0,1,prices);
    // }
};