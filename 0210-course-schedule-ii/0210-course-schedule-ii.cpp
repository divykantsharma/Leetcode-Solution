class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N=numCourses;       //Topo Sort using BFS - Kahn's Algo
	    vector<int> adj[N];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
	    // for(int i=0;i<prerequisites.size();i++){
	    //     adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
	    // }
        vector<int> indegree(N,0);
        for(int i=0;i<N;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
               q.push(i); 
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(ans.size()==N) return ans;
        else return {}; 
    }
};