//converted to - https://leetcode.com/problems/subarray-sum-equals-k/
class Solution{
public:
    int numberOfSubarrays(vector<int>& nums,int k){
        for(auto &it:nums){
            if(it%2==0) it=0;   //even
            else it=1;  //odd
        }
        unordered_map<int,int> mp;
        int prefSum=0,count=0;
        for(int i=0;i<nums.size();i++){
            prefSum+=nums[i];
            if(prefSum==k) count++;
            if(mp.find(prefSum-k)!=mp.end()){
                count+=mp[prefSum-k];
            }
            mp[prefSum]++;
        }
        return count;
    }
};