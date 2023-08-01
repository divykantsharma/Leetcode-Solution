class Solution {
public:
    //14 July - Daily Streak - NOW DONE
    //TC->O(N) , SC->O(N)
    int longestSubsequence(vector<int>& arr, int difference){
        int n=arr.size();
        int maxi=1;
        unordered_map<int,int> dp;
        for(int i=0;i<n;i++){
            int temp=arr[i]-difference;
            int tempans=0;
            if(dp.find(temp)!=dp.end()) tempans=dp[temp];
            dp[arr[i]]=1+tempans;
            maxi=max(maxi,dp[arr[i]]);
        }
        return maxi;
    }


    //TLE - TC->O(N^2) - STRIVER APPROACH
    // int longestSubsequence(vector<int>& arr, int difference){
    //     int n=arr.size();
    //     int maxi=1;
    //     vector<int> dp(n,1);
    //     for(int i=0;i<n;i++){
    //         for(int prev=0;prev<i;prev++){
    //             if((arr[i]-arr[prev])==difference && 1+dp[prev]>dp[i]){
    //                 dp[i]=1+dp[prev];
    //             }
    //         }
    //         maxi=max(maxi,dp[i]);
    //     }
    //     return maxi;
    // }
};