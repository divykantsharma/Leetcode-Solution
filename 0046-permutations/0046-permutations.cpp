class Solution {
public:
    //METHOD 1 - USING STL
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     sort(nums.begin(),nums.end());
    //     do{
    //         ans.push_back(nums);
    //     } while(next_permutation(nums.begin(),nums.end()));
    //     return ans;
    // }



    //METHOD 2 - ADITYA VERMA APPROACH
    // void solve(vector<int> nums,vector<int> op,vector<vector<int>>& ans){
    //     if(nums.size()==0){
    //         ans.push_back(op);
    //         return;
    //     }
    //     for(int i=0;i<nums.size();i++){
    //         //way 1 of restoring vector
    //         op.push_back(nums[i]);
    //         nums.erase(nums.begin()+i);
    //         solve(nums,op,ans);
    //         int element=op[op.size()-1];
    //         op.pop_back();
    //         nums.insert(nums.begin()+i,element);
    //         //way 2 of restoring vector
    //         // vector<int> temp(ip.begin(),ip.end());
    //         // op.push_back(temp[i]);
    //         // temp.erase(temp.begin()+i);
    //         // solve(temp,op,ans);
    //         // op.pop_back();
    //     }
    //     return;
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> op;
    //     solve(nums,op,ans);
    //     return ans;
    // }



    //METHOD 3 - LOVE BABBAR MOST OPTIMIZED
    void solve(vector<int> nums,int index,vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,index+1,ans);
            swap(nums[index],nums[i]);           //Back track
        }
    }
    vector<vector<int>> permute(vector<int>& nums){
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};