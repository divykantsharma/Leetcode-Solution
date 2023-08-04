class Solution {
public:
    int longestOnes(vector<int>& nums,int k){
        int i=0,j=0,countZero=0;
        int maxi=INT_MIN;
        while(j<nums.size()){
            if(nums[j]==1) j++;
            else if(nums[j]==0 && countZero<k){
                j++;
                countZero++;
            }
            else if(nums[j]==0 && countZero>=k){
                while(countZero>=k){
                    if(nums[i]==0) countZero--;
                    i++;
                }
            }
            maxi=max(maxi,j-i);
        }
        return maxi;
    }


    //TLE - TC->O(N^2) , SC->O(1) - (34/55) testcases passed
    // int longestOnes(vector<int>& nums,int k){
    //     if(nums.size()==k) return nums.size();
    //     int n=nums.size(),maxi=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         int temp=k;
    //         int count=0;
    //         for(int j=i;j<n;j++){
    //             if(nums[j]==1) count++;
    //             else if(nums[j]==0 && temp>0){
    //                 count++;
    //                 temp--;
    //             }
    //             else if(nums[j]==0 && temp<=0){
    //                 break;
    //             }
    //         }
    //         maxi=max(maxi,count);
    //     }
    //     return maxi;
    // }
};