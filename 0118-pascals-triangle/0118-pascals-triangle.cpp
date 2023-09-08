class Solution {
public:
    //BRUTE FORCE - TC->O(N*N*R)~O(N^3)
    int ncr(int n,int r){
        long long int res=1;
        for(int i=0;i<r;i++){
            res=res*(n-i);
            res=res/(i+1);
        }
        return res;
    }
    vector<vector<int>> generate(int n){
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            vector<int> temp;
            for(int j=0;j<=i;j++){
                temp.push_back(ncr(i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};