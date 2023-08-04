class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end()); 
        int lo=0,hi=nums.size()-1;
        int count=0;
        while(lo<hi){
            if(nums[lo]+nums[hi]==k){ 
                count++;
                nums[lo]=-1;nums[hi]=-1; 
                lo++,hi--;
            }
            else if(nums[lo]+nums[hi]<k) lo++; 
            else hi--;
        }
        return count;
    }
};