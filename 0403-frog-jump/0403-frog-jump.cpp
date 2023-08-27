class Solution{
public:
    //MEMOIZATION 
    bool f(int index,int jump,vector<int>& stones,vector<vector<int>>& dp){
        if(index==stones.size()-1) return true;
        if(dp[index][jump]!=-1) return dp[index][jump];
        for(int i=index+1;i<stones.size();i++){
            if(stones[i]-stones[index]>jump+1) break;
            for(int j=-1;j<2;j++){
                if(stones[i]-stones[index]==jump+j){
                    if(f(i,jump+j,stones,dp)) return dp[index][jump]=true;
                }
            }
        }
        return dp[index][jump]=false;
    }
    bool canCross(vector<int>& stones){
        int n=stones.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,stones,dp);
    }


    //RECURSION - TLE (15/52) TC passed
    // bool f(int index,int jump,vector<int>& stones){
    //     if(index==stones.size()-1) return true;
    //     bool ans=false;
    //     for(int i=index+1;i<stones.size();i++){
    //         if(stones[i]-stones[index]>jump+1) break;
    //         for(int j=-1;j<2;j++){
    //             if(stones[i]-stones[index]==jump+j){
    //                 ans=f(i,jump+j,stones)||ans;
    //             }
    //         }
    //     }
    //     return ans;
    // }
    // bool canCross(vector<int>& stones){
    //     if(stones[1]-stones[0]>1) return false;
    //     return f(0,1,stones);
    // }
};