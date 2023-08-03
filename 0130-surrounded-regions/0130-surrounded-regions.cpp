class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board,
                            int delrow[],int delcol[]){
        vis[row][col]=1;
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && 
                    board[nrow][ncol]=='O' && !vis[nrow][ncol]){
                dfs(nrow,ncol,vis,board,delrow,delcol);
            } 
        }

    }
    void solve(vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,delrow,delcol);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                dfs(m-1,j,vis,board,delrow,delcol);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,delrow,delcol);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,vis,board,delrow,delcol);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        return;
    }
};