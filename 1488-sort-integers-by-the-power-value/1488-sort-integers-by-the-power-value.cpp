class Solution {
public:
    int f(int x){
        if(x==1)return 0;
        if(x%2==0) return 1+f(x/2);
        else return 1+f((3*x)+1);
    }
    int getKth(int lo, int hi, int k){
        vector<pair<int,int>> ans;
        for(int i=lo;i<=hi;i++){
            ans.push_back({f(i),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};