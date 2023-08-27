class Solution {
public:
    //BINARY SEARCH IN A 2D MATRIX
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        int n=matrix.size(),m=matrix[0].size();
        int i=0,j=m-1;
        while(i>=0 && i<n && j>=0 && j<m){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--; 
            else if(matrix[i][j]<target) i++;
        }
        return false;
        // int m=matrix.size();
        // int n=matrix[0].size();
        // int start=0;
        // int end=n-1;
        // while(start>=0 && start<m && end>=0 && end<n){
        //     if(matrix[start][end]==target) return true;
        //     else if(matrix[start][end]>target) end--;
        //     else if(matrix[start][end]<target) start++;
        // }
        // return false;
    }
};