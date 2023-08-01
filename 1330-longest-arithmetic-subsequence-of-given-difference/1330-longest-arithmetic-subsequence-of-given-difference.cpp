class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference){
        int ans=0;
        //14 July - though samajh aagya apar firse karo
        unordered_map<int,int> dp;
        for(int i=0;i<arr.size();i++){
            int temp=arr[i]-difference;
            int tempans=0;
            if(dp.find(temp)!=dp.end()){
                tempans=dp[temp];
            }
            dp[arr[i]]=1+tempans;

            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};