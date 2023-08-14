class Solution {
public:
    int singleNumber(vector<int>& nums){
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans ^= nums[i];     //a^a=0 and a^0=a
        }
        return ans;
    }
};