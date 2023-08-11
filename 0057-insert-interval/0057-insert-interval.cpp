class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        intervals.push_back(newInterval);           //ONLY THIS LINE IS NEW
        vector<vector<int>> ans;                    //LAST TAK POORA SAME CODE OF MERGE INTERVAL
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        for(auto it:intervals){
            if(it[0]<=temp[1]){
                temp[1]=max(it[1],temp[1]);
            }
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};