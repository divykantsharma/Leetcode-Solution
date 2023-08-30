class Solution{
public:
    bool isPossible(int m,vector<int>& nums,int k){
        int count=1,sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>m) return false;
            sum+=nums[i];
            if(sum>m){
                count++;
                sum=nums[i];
            }
            if(count>k) return false;
        }
        return true;
    }
    int splitArray(vector<int>& nums,int k){
        int s=0,e=accumulate(nums.begin(),nums.end(),0),ans=-1;
        while(s<=e){
            int m=s+(e-s)/2;
            if(isPossible(m,nums,k)){
                ans=m;
                e=m-1;
            }
            else s=m+1;
        }
        return ans;
    }
};