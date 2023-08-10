class Solution{
public:
    int atmostSubarray(vector<int>& nums,int k){
        int i=0,j=0;
        int count=0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp.size()>k){
                while(mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]); 
                    i++;
                }
            }
            if(mp.size()<=k){
                count+=j-i+1;
                j++;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums,int k){
        return atmostSubarray(nums,k)-atmostSubarray(nums,k-1);
    }
};