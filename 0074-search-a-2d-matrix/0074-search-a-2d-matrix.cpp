class Solution {
public:
    //BINARY SEARCH - TC->O(log(M*N)) - as the given matrix is SORTED
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;
        while(i>=0 && i<n && j>=0 && j<m){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--; 
            else if(matrix[i][j]<target) i++;
        }
        return false;
    }
};