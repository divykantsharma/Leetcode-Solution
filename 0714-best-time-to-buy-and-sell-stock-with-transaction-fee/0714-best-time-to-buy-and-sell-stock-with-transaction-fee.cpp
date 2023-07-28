class Solution {
public:
    // same code as Best Time to Buy and Sell Stock II , just deduct the transaction fee after one transaction
    //SPACE OPTIMIZATION
    int maxProfit(vector<int>& prices, int fee) {
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
                    profit=max(prices[index]+ahead[1]-fee,0+ahead[0]);  //fee is deducted here
                }
                cur[buy]=profit;
            }
            ahead=cur;
        }
        return ahead[1]; //as hum n-1 se 0 par jaa rahe hei toh answer will be stored in 0 only 
    }
};