class Solution {
public:
    //BINARY SEARCH - STRIVER
    //Unsorted part of the array may or may not have the answer therefore pick the min from the sorted portion and then only remove the sorted part from your search space;
    int findMin(vector<int>& nums) {  
        int s=0,e=nums.size()-1,ans=INT_MAX; 
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[s]<=nums[e]){   //condition for optimizing the answer
                ans=min(ans,nums[s]);
                break;
            }
            if(nums[s]<=nums[m]){
                ans=min(ans,nums[s]);
                s=m+1;
            }
            else if(nums[m]<nums[e]){
                ans=min(ans,nums[m]);
                e=m-1;
            }
        }
        return ans;
    }


    // //BINARY SEARCH - ADITYA VERMA
    // int findMin(vector<int>& nums) {  
    //     int n=nums.size();  
    //     int start=0,end=n-1; 
    //     while(start<=end){
    //         if(nums[start]<=nums[end]) return nums[start]; //Base case to check if start element is smaller then the last element return then its already sorted , and minimum element is present at the start
    //         int mid=start+(end-start)/2;
    //         int next=(mid+1)%n;
    //         int prev=(mid+n-1)%n;
    //         if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]) return nums[mid];
    //         if(nums[start]<=nums[mid]) start=mid+1;
    //         else if(nums[mid]<=nums[end]) end=mid-1;
    //     }
    //     return -1;
    // }
};