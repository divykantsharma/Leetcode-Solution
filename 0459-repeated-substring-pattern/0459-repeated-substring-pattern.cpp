class Solution {
public:
    bool repeatedSubstringPattern(string s){
        int n=s.length();
        for(int i=0;i<n/2;i++){
            string p=s.substr(0,i+1);
            int m=p.length();
            if(n%m!=0) continue;
            else{
                int temp=n/m;
                string t="";
                while(temp){
                    t+=p;
                    temp--;
                }
                if(t==s) return true;
            }
        }
        return false;
    }
};