class Solution{
public:
    int maximalNetworkRank(int n,vector<vector<int>>& roads){ 
        vector<int> adj[n]; 
        for(int i=0;i<roads.size();i++){ 
            adj[roads[i][0]].push_back(roads[i][1]); 
            adj[roads[i][1]].push_back(roads[i][0]); 
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){ 
            for(int j=i+1;j<n;j++){ 
                int comp=adj[i].size()+adj[j].size(); 
                for(auto it:adj[j]){
                    if(it==i) comp--;
                }
                maxi=max(maxi,comp); 
            }
        }
        return maxi; 
    }
};