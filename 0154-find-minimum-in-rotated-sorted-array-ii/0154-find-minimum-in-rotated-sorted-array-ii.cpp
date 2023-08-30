class Solution {
public:
    int findMin(vector<int>& nums) {
        int s=0,e=nums.size()-1,ans=INT_MAX; 
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[s]==nums[m] && nums[m]==nums[e]){//ONLY extra condition from find min in sorted 1   
                ans=min(ans,nums[s]);
                s++,e--;
                continue;
            }
            if(nums[s]<=nums[m]){
                ans=min(ans,nums[s]);
                s=m+1;
            }
            else{
                ans=min(ans,nums[m]);
                e=m-1;
            }
        }
        return ans;
    }
};