class Solution{
public:
    int maxScore(vector<int>& cardPoints,int k){
        int totalSum=accumulate(cardPoints.begin(),cardPoints.end(),0);
        int n=cardPoints.size();
        int winSize=n-k;
        if(n==k) return totalSum;
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
};