class Solution {
public:
    bool checkSubarraySum(vector<int>& nums,int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int> mp;
        mp[0]=0;    //to check for cases when sum%k==0
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(mp.find(sum%k)!=mp.end()){
                if(mp[sum%k]<i) return true;
            }
            else{
                mp[sum%k]=i+1;
            }
        }
        return false;
    }


    //TLE - TC->O(N^2) , SC->O(N)
    // bool checkSubarraySum(vector<int>& nums,int k) {
    //     set<int> st;    //multiples of k
    //     int sum=accumulate(nums.begin(),nums.end(),0);
    //     for(int i=1;i<=(sum/k);i++){
    //         st.insert(i*k);
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         int total=nums[i];
    //         for(int j=i+1;j<nums.size();j++){
    //             total+=nums[j];
    //             if(st.find(total)!=st.end()) return true;
    //         }
    //     }
    //     return false;
    // }
};