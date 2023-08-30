class Solution{
public:
    long long minimumReplacement(vector<int>& nums){
        long long ans=0,next=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]<=next){
                next=nums[i];
                continue;
            }
            long long parts=ceil(nums[i]/(double)next);
            ans+=parts-1;
            next=nums[i]/parts;
        }
        return ans;
    }
};