class Solution {
public:
    //NEW ALGORITHM USING BINARY SEARCH
    int lengthOfLIS(vector<int>& nums){
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=0;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])- temp.begin();
                temp[ind]=nums[i];
            }
        }
        return temp.size();
    }


    //NEW ALGORITHM - USING TABULATION
    // int lengthOfLIS(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n,1);
    //     int maxi=1;
    //     for(int ind=0;ind<n;ind++){
    //         for(int prev=0;prev<ind;prev++){
    //             if(nums[prev]<nums[ind]){
    //                 dp[ind]=max(1+dp[prev],dp[ind]);
    //             }
    //             maxi=max(maxi,dp[ind]);
    //         }
    //     }
    //     return maxi;
    // }


    //SPACE OPTIMIZATION
    // int lengthOfLIS(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> next(n+1,0),cur(n+1,0);
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
    //             int notpick=0+next[prev_ind+1];
    //             int pick=0;
    //             if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
    //                 pick=1+next[ind+1];
    //             }
    //             cur[prev_ind+1]=max(pick,notpick);
    //         }
    //         next=cur;
    //     }
    //     return next[-1+1];
    // }


    //TABULATION
    // int lengthOfLIS(vector<int>& nums){
    //     int n=nums.size();
    //     vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //     for(int ind=n-1;ind>=0;ind--){
    //         for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
    //             int notpick=0+dp[ind+1][prev_ind+1];
    //             int pick=0;
    //             if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
    //                 pick=1+dp[ind+1][ind+1];
    //             }
    //             dp[ind][prev_ind+1]=max(pick,notpick);
    //         }
    //     }
    //     return dp[0][-1+1];
    // }


    //MEMOIZATION
    // int f(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>& dp){
    //     int n=nums.size();
    //     if(ind==n) return 0;
    //     if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
    //     int notpick=0+f(ind+1,prev_ind,nums,dp);
    //     int pick=0;
    //     if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
    //         pick=1+f(ind+1,ind,nums,dp);
    //     }
    //     return dp[ind][prev_ind+1]=max(pick,notpick);
    // }
    // int lengthOfLIS(vector<int>& nums){
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //     return f(0,-1,nums,dp);
    // }


    //RECURSION - TLE
    // int f(int ind,int prev_ind,vector<int>& nums){
    //     int n=nums.size();
    //     if(ind==n) return 0;
    //     int notpick=0+f(ind+1,prev_ind,nums);
    //     int pick=0;
    //     if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
    //         pick=1+f(ind+1,ind,nums);
    //     }
    //     return max(pick,notpick);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     return f(0,-1,nums);
    // }
};