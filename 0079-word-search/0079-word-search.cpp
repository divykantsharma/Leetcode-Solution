class Solution{
public:
    bool dfs(vector<vector<char>> &board,vector<vector<int>> &vis,string &word,int i,int j,int idx){
        if(idx==word.size()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j]==1 || board[i][j]!=word[idx]){
            return false;
        }
        vis[i][j]=1;
        bool ls=dfs(board,vis,word,i,j-1,idx+1); // left
        bool rs=dfs(board,vis,word,i,j+1,idx+1); // right
        bool ds=dfs(board,vis,word,i+1,j,idx+1); // down
        bool us=dfs(board,vis,word,i-1,j,idx+1); // up
        vis[i][j] = 0;  //backtrack
        return ls || rs || ds || us;
    }
    bool exist(vector<vector<char>>& board,string word){
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && word[0]==board[i][j]){
                    if(dfs(board,vis,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};