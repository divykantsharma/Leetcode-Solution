class Solution{
public:
    bool f(vector<int>& nums,int i,vector<int>& dp){
        if(i==nums.size()) return true;
        if(dp[i]!=-1) return dp[i];
        if(i+1<nums.size() && nums[i]==nums[i+1]){  //1st condition
            if(f(nums,i+2,dp)) return dp[i]=true;
            if(i+2<nums.size() && nums[i+2]==nums[i]){  //2nd condition
                if(f(nums,i+3,dp)) return dp[i]=true;
            }
        }
        if(i+2<nums.size() && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i]+2){    //3rd condition
            if(f(nums,i+3,dp)) return dp[i]=true;
        }
        return dp[i]=false;
    }
    bool validPartition(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(nums,0,dp);
    }


    //RECURSION , TLE - (54/117) testcases passed
    // bool f(vector<int>& nums,int i){
    //     if(i==nums.size()) return true;
    //     if(i+1<nums.size() && nums[i]==nums[i+1]){
    //         if(f(nums,i+2)) return true;
    //         if(i+2<nums.size() && nums[i+2]==nums[i]){
    //             if(f(nums,i+3)) return true;
    //         }
    //     }
    //     if(i+2<nums.size() && nums[i+1]==nums[i]+1 && nums[i+2]==nums[i]+2){
    //         if(f(nums,i+3)) return true;
    //     }
    //     return false;
    // }
    // bool validPartition(vector<int>& nums){
    //     return f(nums,0);
    // }
};