class Solution{
public:
    //USING UNORDERED SET - TC->O(NlogN)
    int longestConsecutive(vector<int>& nums){
        if(nums.empty()) return 0;
        unordered_set<int> st;
        for(auto it:nums) st.insert(it);
        int maxi=1;
        for(auto it:nums){
            if(st.find(it-1)==st.end()){
                int num1=it+1;
                while(st.find(num1)!=st.end()){
                    num1++;
                }
                maxi=max(maxi,num1-it);
            }
        }
        return maxi;
    }


    //TC->O(NlogN)
    // int longestConsecutive(vector<int>& nums){
    //     sort(nums.begin(),nums.end());
    //     int n=nums.size();
    //     int count=1,maxi=1;
    //     if(n==1) return 1;
    //     if(n==0) return 0;
    //     for(int i=0;i<n-1;i++){
    //         if(nums[i]==nums[i+1]-1){
    //             count++;
    //             maxi=max(maxi,count);
    //         }
    //         else if(nums[i]==nums[i+1]) continue;
    //         else count=1;
    //     }
    //     return maxi;
    // }


    //USING LIS CONCEPT , TC->O(N^2) , TLE - (69/73) test saces passed
    // int longestConsecutive(vector<int>& nums){
    //     sort(nums.begin(),nums.end());
    //     if(nums.size()==0) return 0;
    //     if(nums.size()==1) return 1;
    //     //now just find the length of LIS;
    //     int n=nums.size();
    //     vector<int> dp(n,1);
    //     int maxi=1;
    //     for(int ind=0;ind<n;ind++){
    //         for(int prev=0;prev<ind;prev++){
    //             if(nums[prev]+1==nums[ind]){
    //                 dp[ind]=max(1+dp[prev],dp[ind]);
    //             }
    //             maxi=max(maxi,dp[ind]);
    //         }
    //     }
    //     return maxi;
    // }
};