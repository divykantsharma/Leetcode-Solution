class Solution {
public:
    //SPACE OPTIMIZATION
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        vector<int> ahead(2,0),cur(2,0);
        ahead[0]=ahead[1]=0;
        for(int index=n-1;index>=0;index--){
            for(int buy=1;buy>=0;buy--){
                if(buy){
                    profit=max(-prices[index]+ahead[0],0+ahead[1]);
                }
                else{
                    profit=max(prices[index]+ahead[1],0+ahead[0]);
                }
                cur[buy]=profit;
            }
            ahead=cur;
        }
        return ahead[1];    //as hum n-1 se 0 par jaa rahe hei toh answer will be stored in 0 only 
    }


    //TABULATION
    // int maxProfit(vector<int>& prices) {
    //     int profit=0;
    //     int n=prices.size();
    //     vector<vector<int>> dp(n+1,vector<int> (2,0));
    //     dp[n][0]=dp[n][1]=0;
    //     for(int index=n-1;index>=0;index--){
    //         for(int buy=1;buy>=0;buy--){
    //             if(buy){
    //                 profit=max(-prices[index]+dp[index+1][0],0+dp[index+1][1]);
    //             }
    //             else{
    //                 profit=max(prices[index]+dp[index+1][1],0+dp[index+1][0]);
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
    //     if(index==n) return 0;
    //     if(dp[index][buy]!=-1) return dp[index][buy];
    //     if(buy){
    //         profit=max(-prices[index]+f(index+1,0,prices,dp),0+f(index+1,1,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[index]+f(index+1,1,prices,dp),0+f(index+1,0,prices,dp));
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
    //     if(index==n) return 0;
    //     if(buy){
    //         profit=max(-prices[index]+f(index+1,0,prices),0+f(index+1,1,prices));
    //     }
    //     else{
    //         profit=max(prices[index]+f(index+1,1,prices),0+f(index+1,0,prices));
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     return f(0,1,prices);
    // }


    //USING LOOPS
    // int maxProfit(vector<int>& prices) {
    //     int profit=0;
    //     for(int i=1;i<prices.size();i++){
    //         if(prices[i]>prices[i-1]){
    //             profit+=(prices[i]-prices[i-1]);
    //         }
    //     }
    //     return profit;
    // }
};