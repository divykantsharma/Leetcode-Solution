class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs){
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<int> dp(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            int first=pairs[i][0];
            for(int prev=0;prev<i;prev++){
                if(pairs[prev][1]<first){
                    dp[i]=max(dp[i],1+dp[prev]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
        // int last=pairs[0][1];
        // for(int i=1;i<n;i++){
        //     if(last<pairs[i][0]){
        //         ans++;
        //         last=pairs[i][1];
        //     }
        // }
    }
};