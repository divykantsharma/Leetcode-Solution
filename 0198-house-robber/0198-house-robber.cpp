class Solution {
public:
    //SPACE OPTIMIZATION
    int rob(vector<int>& nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick += prev2;
            int nonPick = 0 + prev;
            int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev= cur_i;
        }
        return prev;
    }


    // TABULATION - WORKS PERFECTLY FINE
    // int solve(int n,vector<int>& arr,vector<int>& dp){
    //     dp[0]= arr[0];
    //     for(int i=1;i<n;i++){
    //         int pick=arr[i];
    //         if(i>1) pick+=dp[i-2];
    //         int nonPick=0+dp[i-1];
    //         dp[i]=max(pick,nonPick);
    //     }
    //     return dp[n-1];
    // }
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     return solve(n,nums,dp);
    // }


    //MEMOIZATION - WORKS PERFECTLY FINE
    // int f(int index,vector<int>& nums,vector<int>& dp){
    //     if(index==0) return nums[0];
    //     if(index<0) return 0;
    //     if(dp[index]!=-1) return dp[index];
    //     int pick=nums[index]+f(index-2,nums,dp);
    //     int notpick=0+f(index-1,nums,dp);
    //     return dp[index]=max(pick,notpick);
    // }
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     return f(n-1,nums,dp);
    // }


    //BASIC RECURSION - TLE 
    // int f(int index,vector<int>& nums){
    //     if(index==0) return nums[0];
    //     if(index<0) return 0;
    //     int pick=nums[index]+f(index-2,nums);
    //     int notpick=0+f(index-1,nums);
    //     return max(pick,notpick);
    // }
    // int rob(vector<int>& nums){
    //     int n=nums.size();
    //     return f(n-1,nums);
    // }
};