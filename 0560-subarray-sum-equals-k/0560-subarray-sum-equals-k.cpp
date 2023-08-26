class Solution {
public:
    //PREFIX SUM + MAP - TC->O(N)
    int subarraySum(vector<int>& nums,int k){
        unordered_map<int,int> mp;
        int prefSum=0,count=0;
        for(int i=0;i<nums.size();i++){
            prefSum+=nums[i];
            if(prefSum==k) count++;
            if(mp.find(prefSum-k)!=mp.end()){
                count+=mp[prefSum-k];
            }
            mp[prefSum]++;
        }
        return count;
    }


    //PREFIX SUM 
    //RUNTIME ERROR - AS CODE HAS TC->O(N^2) - (90/93) testcases passed
    // int subarraySum(vector<int>& nums,int k){
    //     int n=nums.size();
    //     vector<int> pref(n,0);
    //     pref[0]=nums[0];
    //     for(int i=1;i<n;i++){
    //         pref[i]=nums[i]+pref[i-1];
    //     }
    //     int count=0;
    //     for(int i=0;i<pref.size();i++){
    //         if(pref[i]==k) count++;
    //         int find=pref[i]-k;
    //         for(int j=0;j<i;j++){
    //             if(pref[j]==find) count++;
    //         }
    //     }
    //     return count;
    // }


    //RUNTIME ERROR - AS CODE HAS TC->O(N^2) - (85/93) testcases passed
    // int subarraySum(vector<int>& nums,int k){
    //     int count =0;
    //     for(int i=0;i<nums.size();i++){
    //         int sum=0;
    //         for(int j=i;j<nums.size();j++){
    //             sum+=nums[j];
    //             if(sum==k) count++;
    //         }
    //     }
    //     return count;
    // }


    //RUNTIME ERROR - AS CODE HAS TC->O(N^3) - (61/93) testcases passed
    // BRUTE FORCE SOLUTION
    // int subarraySum(vector<int>& nums,int target){
    //     int count =0;
    //     for(int i=0;i<nums.size();i++){
    //         for(int j=i;j<nums.size();j++){
    //             int sum=0;
    //             for(int k=i;k<=j;k++){
    //                 sum+=nums[k];
    //             }
    //             if(sum==target) count++;
    //         }
    //     }
    //     return count;
    // }
};