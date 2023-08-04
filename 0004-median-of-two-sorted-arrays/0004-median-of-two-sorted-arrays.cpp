class Solution {
public:
    //TC->O(Nlog(M+N))
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){ 
        vector<int> nums=nums1; 
        for(int i=0;i<nums2.size();i++){ 
            nums.push_back(nums2[i]);
        }
        sort(nums.begin(),nums.end()); 
        int n=nums.size();
        if(n%2==0){ 
            int ans=(double)(nums[(n-1)/2]+nums[n/2]); 
            return ans/2.0;
        }
        else{
            return (double)nums[n/2]; 
        }
    }
};