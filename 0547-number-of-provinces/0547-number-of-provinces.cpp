class Solution {
public:
    void dfs(int node,vector<int> adjLs[],vector<int>& vis){
        vis[node]=1;
        for(auto it:adjLs[node]){
            if(!vis[it]){
                dfs(it,adjLs,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected){    //n*n matrix therefore 0 based index
        int V=isConnected.size();
        vector<int> adjLs[V];   //CREATING OUR OWN ADJACENCY LIST
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        int count=0;    //count will contain the number of provinces we have
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;        //jitni baar dfs call alag se karna padega utni hi province hongi
                dfs(i,adjLs,vis);   
            }
        }
        return count;
    }
};