class Solution{
public:
    int bestClosingTime(string customers){
        int ans=0,maxi=0;
        int penalty=0;
        for(int i=0;i<customers.length();i++){
            if(customers[i]=='Y') penalty++;
            else penalty--;
            if(penalty>maxi){
                maxi=penalty;
                ans=i+1;
            }
        }
        return ans;
    }
};