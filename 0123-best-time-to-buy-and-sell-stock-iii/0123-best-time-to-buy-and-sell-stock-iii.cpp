class Solution {
public:
    //SPACE OPTIMIZATION
        int maxProfit(vector<int>& prices){
        int profit=0;
        int n=prices.size();
        vector<vector<int>> ahead(2,vector<int>(3,0));
        vector<vector<int>> cur(2,vector<int>(3,0));
        //we can ignore the base cases as when we initiated the dp matrix we already set all values as 0;
        for(int index=n-1;index>=0;index--){    
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy){
                        profit=max(-prices[index]+ahead[0][cap],0+ahead[1][cap]);
                    }
                    else{
                        profit=max(prices[index]+ahead[1][cap-1],0+ahead[0][cap]);
                    }
                    cur[buy][cap]=profit;
                }
            }
            ahead=cur;
        }
        return ahead[1][2];
    }


    //TABULATION
    // int maxProfit(vector<int>& prices){
    //     int profit=0;
    //     int n=prices.size();
    //     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //     //we can ignore the base cases as when we initiated the dp matrix we already set all values as 0;
    //     // for(int index=0;index<=n-1;index++){     
    //     //     for(int buy=0;buy<=1;buy++){
    //     //         dp[index][buy][0]=0;
    //     //     }
    //     // }
    //     // for(int buy=0;buy<=1;buy++){
    //     //     for(int cap=0;cap<=2;cap++){
    //     //         dp[n][buy][cap]=0;
    //     //     }
    //     // }
    //     for(int index=n-1;index>=0;index--){
    //         for(int buy=0;buy<=1;buy++){
    //             for(int cap=1;cap<=2;cap++){
    //                 if(buy){
    //                     profit=max(-prices[index]+dp[index+1][0][cap],0+dp[index+1][1][cap]);
    //                 }
    //                 else{
    //                     profit=max(prices[index]+dp[index+1][1][cap-1],0+dp[index+1][0][cap]);
    //                 }
    //                 dp[index][buy][cap]=profit;
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    // }


    //MEMOIZATION
    // int f(int index,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
    //     int profit=0;
    //     int n=prices.size();
    //     //Base Case
    //     if(index==n || cap==0) return 0;
    //     if(dp[index][buy][cap]!=-1) return dp[index][buy][cap];
    //     if(buy){
    //         profit=max(-prices[index]+f(index+1,0,cap,prices,dp),0+f(index+1,1,cap,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[index]+f(index+1,1,cap-1,prices,dp),0+f(index+1,0,cap,prices,dp));
    //     }
    //     return dp[index][buy][cap]=profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //     return f(0,1,2,prices,dp);
    // }


    //RECURSION - TLE
    // int f(int index,int buy,int cap,vector<int>& prices){
    //     int profit=0;
    //     int n=prices.size();
    //     //Base Case
    //     if(index==n || cap==0) return 0;
    //     if(buy){
    //         profit=max(-prices[index]+f(index+1,0,cap,prices),0+f(index+1,1,cap,prices));
    //     }
    //     else{
    //         profit=max(prices[index]+f(index+1,1,cap-1,prices),0+f(index+1,0,cap,prices));
    //     }
    //     return profit;
    // }
    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     return f(0,1,2,prices);
    // }
};