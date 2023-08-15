class Solution {
public:
    int ncr(int n,int r){
        long long int res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<int> getRow(int rowIndex){
        vector<int> ans;
        for(int i=0;i<=rowIndex;i++){
            ans.push_back(ncr(rowIndex,i));
        }
        return ans;
    }
};