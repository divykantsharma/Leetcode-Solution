class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& temp){
        //STACK BASED SOLUTION - NGR
        stack<pair<int,int>> s;
        vector<int> ans;
        for(int i=temp.size()-1;i>=0;i--){
            if(s.size()==0){
                ans.push_back(0);
                s.push({temp[i],i});
            }
            else if(!s.empty() && s.top().first>temp[i]){
                ans.push_back(s.top().second-i);
                s.push({temp[i],i});
            }
            else if(!s.empty() && s.top().first<=temp[i]){
                while(!s.empty() && s.top().first<=temp[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ans.push_back(0);
                    s.push({temp[i],i});
                }
                else{
                    ans.push_back(s.top().second-i);
                    s.push({temp[i],i});
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

        // ARRAY APPROACH - BUT TIME LIMIT EXCEEDED
        // vector<int> ans(temperatures.size(),0);
        // for(int i=0;i<temperatures.size();i++){
        //     for(int j=i+1;j<temperatures.size();j++){
        //         if(temperatures[j]>temperatures[i]){
        //             ans[i]=j-i;
        //             break;
        //         }
        //     }
        // }
        // return ans;
};