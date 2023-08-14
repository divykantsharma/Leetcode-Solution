class Solution {
public:
    //BINARY SEARCH - though the given array is not sorted (concept of BINARY SEARCH ANSWER)
    int BinarySearch(vector<int>& nums){
        int n=nums.size();
        if(n==1) return 0;
        int start=0,end=n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(mid>0 && mid<n-1){
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
                else if(nums[mid-1]>nums[mid]) end=mid-1;
                else start=mid+1;
            }
            else if(mid==0){
                if(nums[mid]>nums[mid+1]) return 0;
                else return 1;
            }
            else if(mid==n-1){
                if(nums[mid]>nums[mid-1]) return n-1;
                else return n-2;
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums){
        return BinarySearch(nums);
    }
};


//LINEAR SEARCH - TLE
// class Solution {
// public:
//     int findPeakElement(vector<int>& nums){
//         int ans=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i+1]<nums[i]){
//                 ans=i;
//                 break;
//             }
//         }
//         return ans;
//     }
// };