class Solution {
public:
    #define pii pair<int,int>  
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i:nums) map[i]++;
        priority_queue<pii , vector<pii> , greater<pii>> minh;
        for(auto it:map){
            // minh.push({it.second,it.first});
            minh.push({map[it.first],it.first});
            if(minh.size()>k){
                minh.pop();
            }
        }
        vector<int> ans;
        while(minh.size()!=0){
            ans.push_back(minh.top().second);
            minh.pop();
        }
        return ans;
    }
};