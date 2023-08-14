class Solution{
public:
    int nearestExit(vector<vector<char>>& maze,vector<int>& entrance){  //bfs hi lagega
        int m=maze.size(),n=maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        vector<int> drow={-1,0,1,0};
        vector<int> dcol={0,1,0,-1};
        maze[entrance[0]][entrance[1]]='+';
        int round=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int row=q.front().first,col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=row+drow[i];
                    int ncol=col+dcol[i];
                    if(nrow<0 || nrow>=m || ncol<0 || ncol>=n || maze[nrow][ncol]=='+') continue;
                    if(nrow==0 || nrow==m-1 || ncol==0 || ncol==n-1){
                        return round;
                    }
                    maze[nrow][ncol]='+';
                    q.push({nrow,ncol});
                }
            }
            round++;
        }
        return -1;
    }
};