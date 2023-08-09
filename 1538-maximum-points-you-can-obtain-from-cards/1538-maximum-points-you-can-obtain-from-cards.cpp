class Solution{
public:
    //SLIDING WINDOW
    int maxScore(vector<int>& cardPoints,int k){
        int totalSum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        int n=cardPoints.size();
        if(n==k) return totalSum;
        int winSize=n-k;
        int maxi=0,sum=0;
        int i=0,j=0;
        while(j<n){
            sum+=cardPoints[j];
            if(j-i+1<winSize) j++;
            else if(j-i+1==winSize){
                maxi=max(maxi,totalSum-sum);
                sum-=cardPoints[i];
                i++,j++;
            }
        }
        return maxi;
    }


    //MEMOIZATION , MLE - (31,40) testcases passed
    // int f(int i,int j,vector<int>& cardPoints,int k,vector<vector<int>>& dp){
    //     if(k==0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int start=cardPoints[i]+f(i+1,j,cardPoints,k-1,dp);
    //     int end=cardPoints[j]+f(i,j-1,cardPoints,k-1,dp);
    //     return dp[i][j]=max(start,end);
    // }
    // int maxScore(vector<int>& cardPoints,int k){
    //     int n=cardPoints.size();
    //     vector<vector<int>> dp(n,vector<int>(n,-1));
    //     return f(0,n-1,cardPoints,k,dp);
    // }


    //MEMOIZATION , MLE - (26,40) testcases passed
    // int f(int i,int j,vector<int>& cardPoints,int k,vector<vector<vector<int>>>& dp){
    //     if(k==0) return 0;
    //     if(dp[i][j][k]!=-1) return dp[i][j][k];
    //     int start=cardPoints[i]+f(i+1,j,cardPoints,k-1,dp);
    //     int end=cardPoints[j]+f(i,j-1,cardPoints,k-1,dp);
    //     return dp[i][j][k]=max(start,end);
    // }
    // int maxScore(vector<int>& cardPoints,int k){
    //     int n=cardPoints.size();
    //     vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
    //     return f(0,n-1,cardPoints,k,dp);
    // }


    //RECUSION , TLE - (22/40) testcases passed
    // int f(int i,int j,vector<int>& cardPoints,int k){
    //     if(k==0) return 0;
    //     int start=cardPoints[i]+f(i+1,j,cardPoints,k-1);
    //     int end=cardPoints[j]+f(i,j-1,cardPoints,k-1);
    //     return max(start,end);
    // }
    // int maxScore(vector<int>& cardPoints,int k){
    //     int n=cardPoints.size();
    //     return f(0,n-1,cardPoints,k);
    // }
};