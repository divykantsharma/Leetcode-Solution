class Solution{
public:
    int findContentChildren(vector<int>& g,vector<int>& s){
        sort(g.rbegin(),g.rend());    //3 2 1
        sort(s.rbegin(),s.rend());    //1 1
        int n=g.size(),m=s.size();
        int count=0;
        int curr=0;
        for(int i=0;i<n;i++){ 
            if(curr<m && g[i]<=s[curr]){ 
                count++;
                curr++;
            }
        }
        return count;
    }
};