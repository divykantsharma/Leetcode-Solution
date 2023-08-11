class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){  //striver
        vector<vector<int>> mergedintervals;
        sort(intervals.begin(),intervals.end());
        vector<int> tempinterval=intervals[0];
        for(auto it:intervals){
            if(it[0]<=tempinterval[1]){
                tempinterval[1]=max(it[1],tempinterval[1]);
            }
            else{
                mergedintervals.push_back(tempinterval);
                tempinterval=it;
            }
        }
        mergedintervals.push_back(tempinterval);
        return mergedintervals;
    }
};