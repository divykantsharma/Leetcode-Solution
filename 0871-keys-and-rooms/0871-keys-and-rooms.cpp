class Solution{
public:
    void dfs(int i,vector<bool>& vis,vector<vector<int>>& rooms){
        vis[i]=1;
        for(auto it:rooms[i]){
            if(!vis[it]) dfs(it,vis,rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms){
        int n=rooms.size();
        vector<bool> vis(n,0);
        dfs(0,vis,rooms);
        for(int i=0;i<vis.size();i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};