class Solution {
public:
    bool canJump(vector<int>& nums){
        int reach=0;
        for(int i=0;i<nums.size();i++){
            if(reach<i) return false;
            reach=max(reach,i+nums[i]);
        }
        return true;
    }


    //MEMOIZATION
    // bool f(int i,vector<int>& nums,vector<int>& dp){
    //     int n=nums.size();
    //     if(i==n-1) return  true;
    //     if(nums[i]==0) return false;
    //     if(dp[i]!=-1) return dp[i];
    //     for(int jump=i+1;jump<=i+nums[i];jump++){
    //         if(jump<nums.size() && f(jump,nums,dp)){
    //             return dp[i]=true;
    //         }
    //     }
    //     return dp[i]=false;
    // }
    // bool canJump(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
    //     return f(0,nums,dp);
    // }


    //RECURSION , TLE - (75/172) testcases passed
    // bool f(int i,vector<int>& nums){
    //     int n=nums.size();
    //     if(i==n-1) return  true;
    //     if(nums[i]==0) return false;
    //     for(int jump=i+1;jump<=i+nums[i];jump++){
    //         if(jump<nums.size() && f(jump,nums)){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // bool canJump(vector<int>& nums){
    //     return f(0,nums);
    // }
};