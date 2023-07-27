class Solution {
public:
    //SPACE OPTIMIZATION
    bool f(int n, int k, vector<int> &arr){
        vector<bool> prev(k+1,false) , cur(k+1,false);
        prev[0]=true , cur[0]=true;
        if(arr[0]<=k) prev[arr[0]]=true;
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=k;target++){
                bool nottake=prev[target];
                bool take=false;
                if(target>=arr[ind]){
                    take=prev[target-arr[ind]];
                }
                cur[target]=take||nottake;
            }
            prev=cur;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums){
        int n=nums.size();
        int totalsum=0;
        for(int i=0;i<n;i++) totalsum+=nums[i];
        if(totalsum%2==1) return false;
        else{
            int k=totalsum/2;
            return f(n-1,k,nums);
        }
    }

    //TABULATION
    // bool canPartition(vector<int>& nums){
    //     int n=nums.size();
    //     int totSum=0;
    //     for(int i=0;i<n;i++) totSum+=nums[i];
    //     if(totSum%2==1) return false;
    //     else{
    //         int k=totSum/2;
    //         vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    //         for(int i=0;i<n;i++) dp[i][0] = true;
    //         if(nums[0]<=k) dp[0][nums[0]] = true;
    //         for(int ind = 1; ind<n; ind++){
    //             for(int target= 1; target<=k; target++){
    //                 bool notTaken = dp[ind-1][target];
    //                 bool taken = false;
    //                     if(nums[ind]<=target)
    //                         taken = dp[ind-1][target-nums[ind]];   
    //                 dp[ind][target]= notTaken||taken;
    //             }
    //         }
    //         return dp[n-1][k];
    //     } 
    // }


    //MEMOIZATION
    // bool f(int index,int target,vector<int>& nums,vector<vector<int>>& dp){
    //     if(target==0) return true;
    //     if(index==0) return nums[0]==target;
    //     if(dp[index][target]!=-1) return dp[index][target];
    //     bool nottake=f(index-1,target,nums,dp);
    //     bool take=false;
    //     if(nums[index]<=target) take=f(index-1,target-nums[index],nums,dp);
    //     return dp[index][target]=take||nottake;
    // }
    // bool canPartition(vector<int>& nums){
    //     int n=nums.size();
    //     int totalsum=0;
    //     for(int i=0;i<n;i++) totalsum+=nums[i];
    //     if(totalsum%2==1) return false;
    //     else{
    //         int k=totalsum/2;
    //         vector<vector<int>> dp(n,vector<int>(k+1,-1));
    //         return f(n-1,k,nums,dp);
    //     }
    // }


    //RECURSION - TLE
    // bool f(int index,int target,vector<int>& nums){
    //     if(target==0) return true;
    //     if(index==0) return nums[0]==target;
    //     bool nottake=f(index-1,target,nums);
    //     bool take=false;
    //     if(nums[index]<=target) take=f(index-1,target-nums[index],nums);
    //     return take||nottake;
    // }
    // bool canPartition(vector<int>& nums){
    //     int sum=0;
    //     for(int i=0;i<nums.size();i++) sum+=nums[i];
    //     if(sum%2!=0) return false;
    //     else return f(nums.size()-1,sum/2,nums);
    // }
};