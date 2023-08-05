class Solution {
public:
    bool isSafe(int row,int col,vector<string> board,int n){
      // check upper element
      int duprow=row;
      int dupcol=col;
      while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row--;
        col--;
      }
      col=dupcol;
      row=duprow;
      while(col>=0){
        if(board[row][col]=='Q') return false;
        col--;
      }
      row=duprow;
      col=dupcol;
      while(row< n && col>=0){
        if(board[row][col]=='Q') return false;
        row++;
        col--;
      }
      return true;
    }
    void solve(int col,vector<string>& board,vector<vector<string>>& ans,int n){
      //Base Case
      if(col==n){
        ans.push_back(board);
        return;
      }
      for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){     //checking is it safe to place the queen at this pos
          board[row][col]='Q';
          solve(col + 1, board, ans, n);
          board[row][col]='.';            //Back tracking
        }
      }
    }
    int totalNQueens(int n){
        vector<vector<string>> ans;
        vector<string> board(n);        //board - [[],[],[],[]]
        string s(n,'.');                //s - "...."
        for (int i=0;i<n;i++) {
            board[i]=s;                 //board - [[ "...."],[ "...."],[ "...."],[ "...."]]
        }
        solve(0,board,ans,n);
        return ans.size();
    }
};