class Solution{
public:
    vector<int> successfulPairs(vector<int>& spells,vector<int>& potions,long long success) {
        int n=spells.size(),m=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<n;i++){
            int count=0;
            int st=0,en=m-1;
            while(st<=en){
                int mid=st+(en-st)/2;
                if(1LL*spells[i]*potions[mid]>=success){
                    en=mid-1;
                }
                else if(1LL*spells[i]*potions[mid]<success) st=mid+1;
            }
            count+=m-st;
            ans.push_back(count);
        }
        return ans;
    }
};