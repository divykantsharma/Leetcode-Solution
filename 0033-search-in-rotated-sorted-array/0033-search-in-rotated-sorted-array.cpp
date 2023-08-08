class Solution {
public:
    //removing the sorted part if element is not present in it - STRIVER
    int search(vector<int>& nums,int target){
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && target<=nums[mid]) hi=mid-1;
                else lo=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[hi]) lo=mid+1;
                else hi=mid-1;   
            }
        }
        return -1;
    }

    //Finding the min element then searcing in 2 sorted arrays - ADITYA VERMA
    // int BinarySearch(vector<int>& nums,int start,int end,int target){
    //     int n=nums.size();
    //     int st=start,en=end;
    //     while(st<=en){
    //         int mid=st+(en-st)/2;
    //         if(nums[mid]==target) return mid;
    //         else if(nums[mid]>target) en=mid-1;
    //         else st=mid+1;
    //     }
    //    return -1;
    // }
    // int findmin(vector<int>& nums){
    //     int n=nums.size();
    //     int start=0;
    //     int end=n-1; 
    //     while(start<=end){
    //         if(nums[start]<=nums[end]) return start; 
    //         int mid=start+(end-start)/2;
    //         int next=(mid+1)%n;
    //         int prev=(mid+n-1)%n;
    //         if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]) return mid;
    //         if(nums[start]<=nums[mid]) start=mid+1;
    //         else if(nums[mid]<=nums[end]) end=mid-1;
    //     }
    //     return -1;
    // }
    // int search(vector<int>& nums,int target){
    //     int n=nums.size();
    //     int minindex=findmin(nums);
    //     int ans1=BinarySearch(nums,0,minindex-1,target);
    //     int ans2=BinarySearch(nums,minindex,n-1,target);
    //     if(ans1==-1) return ans2;
    //     else return ans1;
    // }
};