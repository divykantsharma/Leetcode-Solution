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


    //RECURSION - TLE (16/52) TC passed
    // bool f(int index,int jump,vector<int>& stones){
    //     if(index==stones.size()-1) return true;
    //     for(int i=index+1;i<stones.size();i++){
    //         if(stones[i]-stones[index]>jump+1) break;
    //         for(int j=-1;j<2;j++){
    //             if(stones[i]-stones[index]==jump+j){
    //                 if(f(i,jump+j,stones)) return true;;
    //             }
    //         }
    //     }
    //     return false;
    // }
    // bool canCross(vector<int>& stones){
    //     int n=stones.size();
    //     return f(0,0,stones);
    // }
};