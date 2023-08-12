class Solution{
public:
    double findMaxAverage(vector<int>& nums,int k){
        int i=0,j=0,sum=0;
        double maxi=INT_MIN;
        while(j<nums.size()){
            sum+=nums[j];
            if(j-i+1<k) j++;
            else{
                maxi=max(maxi,(((1.0)*sum)/k));
                sum-=nums[i];
                i++,j++;
            }
        }
        return maxi;
    }
};