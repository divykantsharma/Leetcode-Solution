class Solution{
public:
    // static bool comp(vector<int>& a,vector<int>& b){     //na use kare toh bhi same hi baat hei 
    //     if(a[0]!=b[0]) return a[0]<b[0];
    //     else return a[1]>b[1];
    // }
    int minTaps(int n,vector<int>& ranges){
        vector<vector<int>> intervals;
        for(int i=0;i<ranges.size();i++){
            intervals.push_back({i-ranges[i],i+ranges[i]});
        }
        sort(intervals.begin(),intervals.end());
        int taps=0,start=0,end=0,i=0;
        while(end<n){
            for(;i<intervals.size() && intervals[i][0]<=start;i++){
                end=max(end,intervals[i][1]);
            }
            if(start==end) return -1;
            start=end;
            taps++;
        }
        return taps;
    }
};