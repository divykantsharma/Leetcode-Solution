class Solution {
public:
    //2 POINTER APPROACH - TC->O(NlogN)+O(N^2) , SC->O(no. of unique triplets)
    vector<vector<int>> threeSum(vector<int>& nums){
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1,k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) j++;
                else if(sum>0) k--;
                else{
                    vector<int> temp={nums[i],nums[j],nums[k]};
                    ans.push_back(temp);
                    j++,k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }   


    //CAN BE DONE USING HASHING - TC->O(N^2)


    //BRUTE FORCE - TC->O(N^3) , SC->O(no. of triplests in set) - TLE (308/312)test case
    // vector<vector<int>> threeSum(vector<int>& nums){
    //     set<vector<int>> st;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             for(int k=j+1;k<n;k++){
    //                 if(nums[i]+nums[j]+nums[k]==0){
    //                     vector<int> temp={nums[i],nums[j],nums[k]};
    //                     sort(temp.begin(),temp.end());
    //                     st.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    //     vector<vector<int>> ans(st.begin(),st.end());
    //     return ans;
    // }
};