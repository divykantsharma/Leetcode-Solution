class Solution {
public:
    //PATTERN 
    // int countVowelStrings(int n) {
    //     int a=1,e=1,i=1,o=1,u=1;
    //     n=n-1;
    //     while(n--){
    //         o+=u;
    //         i+=o;
    //         e+=i;
    //         a+=e;
    //     }        
    //     return a+e+i+o+u;
    // }

    int f(int i,int n,string& vowels){
        if(n==0) return 1;
        if(i>=5) return 0;
        int pick=f(i,n-1,vowels);
        int notPick=f(i+1,n,vowels);
        return pick + notPick;
    }
    int countVowelStrings(int n){
        string vowels="aeiou";
        return f(0,n,vowels);
    }
};