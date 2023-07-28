class Solution {
public:
    // same code as Best Time to Buy and Sell Stock III , just replace cap=2 to k
    //SPACE OPTIMIZATION
    int maxProfit(int k, vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        vector<vector<int>> cur(2,vector<int>(k+1,0));
        //we can ignore the base cases as when we initiated the dp matrix we already set all values as 0;
        for(int index=n-1;index>=0;index--){    
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
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
        return ahead[1][k];
    }
};