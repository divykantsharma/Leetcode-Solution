class Solution {
public:
    //TABULATION
    int minimumDeleteSum(string s1, string s2){
        int n=s1.length(),m=s2.length();
        int sum1=0,sum2=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++) sum1+=s1[i];       //ASCII sum of whole strings 
        for(int i=0;i<m;i++) sum2+=s2[i];
        // for(int j=0;j<=m;j++) dp[0][j]=0;    //Base Cases
        // for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=s1[i-1]+dp[i-1][j-1];   //only change from LCS
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ans=dp[n][m];
        return sum1+sum2-(2*ans);
    }
};