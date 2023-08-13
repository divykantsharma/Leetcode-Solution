class RecentCounter{
public:
    queue<int> q;
    RecentCounter(){
        
    }
    int ping(int t){
        q.push(t);
        int m=q.front();
        while(!q.empty() && m<t-3000){
            q.pop();
            m=q.front();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */