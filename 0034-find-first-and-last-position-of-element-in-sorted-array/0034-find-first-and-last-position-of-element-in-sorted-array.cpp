class Solution {
public:
    int LastOccurence(vector<int>& nums,int target){     //returns the last occurence of an target
        int n=nums.size();
        int start=0,end=n-1;
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                res=mid;
                start=mid+1;
            }
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return res;
    }
    int FirstOccurence(vector<int>& nums,int target){     //returns the first occurence of an target
        int n=nums.size();
        int start=0,end=n-1;
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                res=mid;
                end=mid-1;
            }
            else if(nums[mid]>target) end=mid-1;
            else start=mid+1;
        }
        return res;
    }
    vector<int> searchRange(vector<int>& nums, int target){
        int first=FirstOccurence(nums,target);
        int last=LastOccurence(nums,target);
        return {first,last};
    }
};