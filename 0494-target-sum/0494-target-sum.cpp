class Solution {
public:
    //RECURSION - NO TLE PERFORMING GOOD
    int f(int ind,int target,vector<int>& nums){
        if(ind==0){
            if(target==0 && nums[0]==0) return 2;       //striver DP 18 check please
            if(target==0 || target==nums[0]) return 1;
            return 0;
        }
        int notpick=f(ind-1,target,nums);
        int pick=0;
        if(nums[ind]<=target) pick=f(ind-1,target-nums[ind],nums);
        return pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int k=totalsum-target;
        if(k<0 || (k%2)==1) return 0;
        return f(n-1,k/2,nums);
    }
};
