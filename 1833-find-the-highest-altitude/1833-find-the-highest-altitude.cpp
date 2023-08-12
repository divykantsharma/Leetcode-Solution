class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        gain.insert(gain.begin(),0);
        for(int i=2;i<gain.size();i++){
            gain[i]=gain[i]+gain[i-1];
        }
        for(auto it : gain){        //just for checking
            cout<<it<<" ";
        }
        return *max_element(gain.begin(),gain.end());
    }
};