class Solution {
public:
    void f(int i,vector<int> can,vector<int> temp,int target,vector<vector<int>>& ans){
        int n=can.size();
        if(i==n){
            if(target==0){
                ans.push_back(temp);
            }
            return;
        }
        if(can[i]<=target){     //pick
            temp.push_back(can[i]);
            f(i,can,temp,target-can[i],ans);
            temp.pop_back();
        }
        f(i+1,can,temp,target,ans);     //not pick
    }
    vector<vector<int>> combinationSum(vector<int>& can,int target){
        vector<vector<int>> ans;
        vector<int> temp;
        f(0,can,temp,target,ans);
        return ans;
    }
};