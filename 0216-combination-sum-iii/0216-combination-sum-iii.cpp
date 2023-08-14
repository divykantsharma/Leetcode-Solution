class Solution {
public:
    void solve(int k,int target,int index,vector<vector<int>>& ans,vector<int>& ds){
        //Base Case
        if(k==0){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        for(int i=index;i<=9;i++){
            if(k>0 && target>=i){
                ds.push_back(i);
                solve(k-1,target-i,i+1,ans,ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n){
        vector<vector<int>> ans;
        vector<int> ds;
        int index=1;
        solve(k,n,index,ans,ds);
        return ans; 
    }
};