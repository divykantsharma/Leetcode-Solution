class Solution {
public:
    static bool comp(vector<int>& a,vector<int>& b){
        if(a[0]!=b[0]) return a[0]<b[0];    //increasing order of width
        else return a[1]>b[1];    //if same width sort in decreasing order of height
    }
    int maxEnvelopes(vector<vector<int>>& envelopes){
        int n=envelopes.size();
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i=1;i<n;i++){
            if(envelopes[i][1]>ans.back()) ans.push_back(envelopes[i][1]);
            else{
                int pos=lower_bound(ans.begin(),ans.end(),envelopes[i][1])-ans.begin();
                ans[pos]=envelopes[i][1];
            }
        }
        return ans.size();
    }


    //TLE - TC->O(N^2) , SC->O(N) - (85/87) testcases passed
    // int maxEnvelopes(vector<vector<int>>& envelopes){
    //     int n=envelopes.size();
    //     sort(envelopes.begin(),envelopes.end());
    //     vector<int> dp(n,1);
    //     int maxi=1;
    //     for(int i=0;i<n;i++){
    //         for(int prev=0;prev<i;prev++){
    //             if(envelopes[i][0]!=envelopes[prev][0] && envelopes[i][1]>envelopes[prev][1]){
    //                 dp[i]=max(dp[i],1+dp[prev]);
    //             }
    //         }
    //         maxi=max(maxi,dp[i]);
    //     }
    //     return maxi;
    // }
};