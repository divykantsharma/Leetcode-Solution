class Solution{
public:
    static bool comp(pair<int,int>& a,pair<int,int>& b){
        return a.second>b.second;
    }
    long long maxScore(vector<int>& nums1,vector<int>& nums2,int k){
        vector<pair<int,int>> vec;
        for(int i=0;i<nums1.size();i++){
            vec.push_back({nums1[i],nums2[i]});
        }
        sort(vec.begin(),vec.end(),comp);
        priority_queue<int,vector<int>,greater<int>> minh;
        long long kSum=0;
        for(int i=0;i<k;i++){
            kSum+=vec[i].first;
            minh.push(vec[i].first);
        }
        long long maxi=kSum*vec[k-1].second;
        for(int i=k;i<nums1.size();i++){
            kSum+=vec[i].first-minh.top();
            minh.pop();
            minh.push(vec[i].first);
            maxi=max(maxi,kSum*vec[i].second);
        }
        return maxi;
    }
};