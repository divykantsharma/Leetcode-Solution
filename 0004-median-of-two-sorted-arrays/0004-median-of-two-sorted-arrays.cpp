class Solution {
public:
    //BINARY SEARCH - TC->O(log(M+N))
    // double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){ 
    //     //LEARN THROUGH BINARY SEARCH
    // }

    //Merging 2 sorted arrays - TC->O(M+N)
    double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){
        int n1=nums1.size(),n2=nums2.size();
        vector<int> arr3;
        int i=0,j=0;
        while(i<n1 && j<n2) {
            if(nums1[i]<nums2[j]) arr3.push_back(nums1[i++]);
            else arr3.push_back(nums2[j++]);
        }
        while(i<n1) arr3.push_back(nums1[i++]);
        while(j<n2) arr3.push_back(nums2[j++]);
        int n=n1+n2;
        if(n%2==1){
            return (double)arr3[n/2];
        }
        return (arr3[n/2]+arr3[(n/2)-1])/2.0;
    }


    //TC->O((M+N)log(M+N))
    // double findMedianSortedArrays(vector<int>& nums1,vector<int>& nums2){ 
    //     vector<int> nums=nums1; 
    //     for(int i=0;i<nums2.size();i++){ 
    //         nums.push_back(nums2[i]);
    //     }
    //     sort(nums.begin(),nums.end()); 
    //     int n=nums.size();
    //     if(n%2==0){ 
    //         int ans=(double)(nums[(n-1)/2]+nums[n/2]); 
    //         return ans/2.0;
    //     }
    //     else{
    //         return (double)nums[n/2]; 
    //     }
    // }
};