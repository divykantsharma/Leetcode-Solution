class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals){
        if(intervals.size()==0) return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int count=-1;   //as tempinterval and intervals[0] will always match, therefore -1
        vector<int> tempinterval=intervals[0];
        for(auto it:intervals){
            if(tempinterval[1]>it[0]){
                count++;
            }
            else tempinterval=it;
        }
        return count;
    }
};