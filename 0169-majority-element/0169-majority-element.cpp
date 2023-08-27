class Solution {
public:
    //MOORE'S VOTING ALGORITHM - TC->O(N)
    int majorityElement(vector<int>& nums){
        int n=nums.size();
        int count=0;
        int el=0;
        for(int i=0;i<n;i++){     //at the end el will contain the majority element 
            if(count==0) el=nums[i];
            if(nums[i]==el) count++;
            else count--;
        }
        //it might be possible ki vector mei majority element ho hi na - isliye verify karlo answer
        //to verify take the count of el and if it is >n/2 it will be your answer
        int times=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el) times++;
        }
        if(times>(n/2)) return el;
        else return -1;     //though question said there will surely be an majority element toh else tak toh kabhi aayenge hi nahi
    }


    //TC->O(NlogN)
    // int majorityElement(vector<int>& nums){
    //     int n = nums.size();
    //     sort(nums.begin(),nums.end());
    //     return nums[n/2];
    // }
};