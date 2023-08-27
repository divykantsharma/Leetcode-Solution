class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix){
        int n=matrix.size(),m=matrix[0].size();
        vector<int> a(m,1),b(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    a[j]=0;
                    b[i]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i]==0) matrix[i][j]=0;
                if(a[j]==0) matrix[i][j]=0;
            }
        }
        return;
    }
};