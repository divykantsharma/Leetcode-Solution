class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
        vector<int> nums=nums1;
        for(int i=0;i<nums2.size();i++){
            nums.push_back(nums2[i]);
        }
        sort(nums.begin(),nums.end());
        if(nums.size()%2==0){
            int pos1=(nums.size()-1)/2;
            int pos2=nums.size()/2;
            int ans=(double)(nums[pos1]+nums[pos2]);
            return ans/2.0;
        }
        else{
            int pos=nums.size()/2;
            return (double)nums[pos];
        }
    }
};