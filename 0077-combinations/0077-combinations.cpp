class Solution {
public:
    void solve(int k,int index,vector<int>& nums,vector<vector<int>>& ans,vector<int>& ds){
        //Base Case
        if(k==0){
            ans.push_back(ds);
            return;
        }

        //traversing nums to get all the possible options
        for(int i=index;i<nums.size();i++){
                ds.push_back(nums[i]);
                solve(k-1,i+1,nums,ans,ds);             //decrementing the value of k
                ds.pop_back();
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> nums;           //as input array nahi diya toh apna khudka array bana liya
        for(int i=1;i<=n;i++){
            nums.push_back(i);
        }
        solve(k,0,nums,ans,ds);
        return ans;
    }
};