class Solution{
public:
    bool isPossible(int mid,vector<int>& nums,int p){ 
        int count=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]-nums[i]<=mid){
                count++;
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums,int p){
        sort(nums.begin(),nums.end());
        int st=0,en=nums[nums.size()-1]-nums[0];
        int ans=0;
        while(st<=en){
            int mid=st+(en-st)/2;
            if(isPossible(mid,nums,p)){
                ans=mid;
                en=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};