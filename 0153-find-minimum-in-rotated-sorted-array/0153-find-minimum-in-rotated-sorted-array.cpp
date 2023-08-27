class Solution {
public:
    //BINARY SEARCH 
    int BinarySearch(vector<int>& nums){
        int n=nums.size();
        int start=0;
        int end=n-1; 
        while(start<=end){
            if(nums[start]<=nums[end]) return nums[start]; //Base case to check if start element is smaller then the last element return then its already sorted , and minimum element is present at the start
            int mid=start+(end-start)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]) return nums[mid];
            if(nums[start]<=nums[mid]) start=mid+1;
            else if(nums[mid]<=nums[end]) end=mid-1;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        return BinarySearch(nums);
    }
};