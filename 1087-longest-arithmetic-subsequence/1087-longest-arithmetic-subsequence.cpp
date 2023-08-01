class Solution {
public:
    //TABULATION
    int longestArithSeqLength(vector<int>& nums){
        int n=nums.size();
        if(n<=2) return n;
        int maxi=0;
        unordered_map<int,int> dp[n+1];  //umap<index,all of it's common diff> [of size n+1 for all indexes]
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int count=1;
                if(dp[j].count(diff)) count=dp[j][diff];
                dp[i][diff]=1+count;
                maxi=max(maxi,dp[i][diff]);
            }
        }
        return maxi;
    }


    //MEMOIZATION - DP + UNORDERED MAP - TLE (48/63) test cases passed
    // int solve(int i,int diff,vector<int>& nums,unordered_map<int,int> dp[]){ 
    //     //backward solve;
    //     if(i<0) return 0;
    //     if(dp[i].count(diff)) return dp[i][diff];
    //     int count=0;
    //     for(int k=i-1;k>=0;k--){
    //         if(nums[i]-nums[k]==diff){
    //             count=max(count,1+solve(k,diff,nums,dp));
    //         }
    //     }
    //     return dp[i][diff]=count;
    // }  
    // int longestArithSeqLength(vector<int>& nums){
    //     int n=nums.size();
    //     if(n<=2) return n;
    //     unordered_map<int,int> dp[n+1];  //umap<index,all of it's common diff> [of size n+1 for all indexes]
    //     int maxi=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             maxi=max(maxi,2+solve(i,nums[j]-nums[i],nums,dp));
    //         }
    //     }
    //     return maxi;
    // }


    //RECURSION - TLE (36/63) test cases passed
    // int solve(int i,int diff,vector<int>& nums){
    //     //backward solve;
    //     if(i<0) return 0;
    //     int count=0;
    //     for(int k=i-1;k>=0;k--){
    //         if(nums[i]-nums[k]==diff){
    //             count=max(count,1+solve(k,diff,nums));
    //         }
    //     }
    //     return count;
    // }  
    // int longestArithSeqLength(vector<int>& nums){
    //     int n=nums.size();
    //     if(n<=2) return n;
    //     int maxi=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             maxi=max(maxi,2+solve(i,nums[j]-nums[i],nums));
    //         }
    //     }
    //     return maxi;
    // }
};