class Solution{
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points){
        int count=points.size()+1;
        sort(points.begin(),points.end(),comp);
        vector<int> temp=points[0];
        for(auto it:points){
            if(it[0]<=temp[1]) count--;
            else temp=it;
        }
        return count;
    }
};