class Solution{
public:
    string predictPartyVictory(string senate){
        queue<int> r,d;
        int n=senate.length();
        for(int i=0;i<n;i++){
            (senate[i]=='R')?r.push(i):d.push(i);
        }
        while(!r.empty() && !d.empty()){
            int r_id=r.front(),d_id=d.front();
            r.pop(),d.pop();
            (r_id<d_id)?r.push(r_id+n):d.push(d_id+n);
        }
        return (r.size()>d.size())?"Radiant":"Dire";
    }
};