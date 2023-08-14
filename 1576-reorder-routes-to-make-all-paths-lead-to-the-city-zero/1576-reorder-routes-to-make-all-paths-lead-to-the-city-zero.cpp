class Solution{
public:
    int dfs(int i,vector<int>& vis,vector<int> adj[],int& count){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[abs(it)]){
                if(it>0) count++;
                dfs(abs(it),vis,adj,count);
            }
        }
        return count;
    }
    int minReorder(int n,vector<vector<int>>& connections){
        int count=0;
        vector<int> adj[n];
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(-it[0]);
        }
        vector<int> vis(n,0);
        dfs(0,vis,adj,count);
        return count;
    }
};