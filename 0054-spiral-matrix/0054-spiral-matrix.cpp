class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m=matrix.size();
        int n=matrix[0].size();
        
        int rs=0;
        int re=m-1;
        int cs=0;
        int ce=n-1;

        int total=n*m;
        int count=0;
        
        while((rs<=re)&&(cs<=ce)){
            for(int i=cs;count<total && i<=ce;i++){
                ans.push_back(matrix[rs][i]);
                count++;
            }
            rs++;
            
            for(int i=rs;count<total && i<=re;i++){
                ans.push_back(matrix[i][ce]);
                count++;
            }
            ce--;
            
                for(int i=ce;count<total && i>=cs;i--){
                ans.push_back(matrix[re][i]);
                count++;
            }
            re--;
            
            for(int i=re;count<total && i>=rs;i--){
                ans.push_back(matrix[i][cs]);
                count++;
            }
            cs++;
        }
        return ans;
    }
};

