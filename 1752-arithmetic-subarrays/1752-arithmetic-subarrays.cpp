class Solution {
public:
    bool isCheck(vector<int>& temp){
        sort(temp.begin(),temp.end());
        if(temp.size()<=2) return true;
        int diff=temp[1]-temp[0];
        for(int i=2;i<temp.size();i++){
            if(temp[i]-temp[i-1]!=diff) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums,vector<int>& l,vector<int>& r){
        int n=nums.size(),m=l.size();
        vector<bool> ans;
        for(int i=0;i<m;i++){
            vector<int> temp(nums.begin()+l[i],nums.begin()+r[i]+1);
            // int st=l[i],en=r[i];
            // vector<int> temp;
            // for(int j=st;j<=en;j++){
            //     temp.push_back(nums[st]);
            // }
            ans.push_back(isCheck(temp));
        }
        return ans;
    }
};