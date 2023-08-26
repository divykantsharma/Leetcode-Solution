class Solution {
public:
//FOR 2 POINTER APPROACH - we must need to sort the array , and sorting requires preservation of indexes therefore in order to reduce the TC we will increase the SC by O(N^2)


    //HASHMAP - TC->O(N) with unordered map , SC->O(N)
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            int b=target-a;
            if(mp.find(b)!=mp.end()){
                return {mp[b],i};
            }
            mp[a]=i;
        }
        return {};
    }


    //TC->O(N^2)
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> ans;
    //     for(int i=0;i<nums.size();i++){
    //         int temp=target-nums[i];
    //         for(int j=0;((j!=i)&&(j<nums.size()));j++){
    //             if(nums[j]==temp){
    //                 ans.push_back(i);
    //                 ans.push_back(j);
    //             }
    //         }
    //     }
    //     return ans;
    // }
};