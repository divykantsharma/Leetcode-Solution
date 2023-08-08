//similar to - https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:
    //PREFIX SUM + MAP - TC->O(N)
    int numSubarraysWithSum(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        int prefSum=0;
        int count=0;
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


    //TC->O(N^2) , TLE-(55/60) testcases passed
    // int numSubarraysWithSum(vector<int>& nums,int goal){
    //     int count=0;
    //     for(int i=0;i<nums.size();i++){
    //         int temp=0;
    //         for(int j=i;j<nums.size();j++){
    //             temp+=nums[j];
    //             if(temp==goal) count++;
    //         }
    //     }
    //     return count;
    // }
};