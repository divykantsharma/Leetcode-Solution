class Solution{
public:
    int videoStitching(vector<vector<int>>& clips,int time){
        sort(clips.begin(),clips.end());
        int taps=0,start=0,end=0,i=0;
        while(end<time){
            for(;i<clips.size() && clips[i][0]<=start;i++){
                end=max(end,clips[i][1]);
            }
            if(start==end) return -1;
            start=end;
            taps++;
        }
        return taps;   
    }
};