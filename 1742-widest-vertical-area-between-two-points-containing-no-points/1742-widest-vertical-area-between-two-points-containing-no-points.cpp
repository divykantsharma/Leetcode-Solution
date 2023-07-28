class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end()); //sorting must be done on the basis of x axis
        int maxi=INT_MIN;
        for(int i=0;i<points.size()-1;i++){
            maxi=max(maxi,points[i+1][0]-points[i][0]);
        }
        return maxi;
    }
};