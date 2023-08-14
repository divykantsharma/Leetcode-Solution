class Solution{
public:
    int minFlips(int a,int b,int c){
        int count=0;
        while(a || b || c){
            if(((a&1)|(b&1))!=(c&1)){
                if((a&1)&(b&1)) count+=2;
                else count+=1;
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return count;
    }


    //WITHOUT KNOWING BIT
    // string decimaltobinary(int n){
    //     string ans="";
    //     while(n){
    //         ans=to_string(n%2)+ans;
    //         n=n/2;
    //     }
    //     return ans;
    // }
    // int minFlips(int a,int b,int c){
    //     string newa=decimaltobinary(a);
    //     string newb=decimaltobinary(b);
    //     string newc=decimaltobinary(c);
    //     int max_len = max(max(newa.length(), newb.length()), newc.length());
	// 	// appending '0's in front of each number
    //     newa = string(max_len - newa.length(), '0') + newa;
    //     newb = string(max_len - newb.length(), '0') + newb;
    //     newc = string(max_len - newc.length(), '0') + newc;
    //     //travrsing the strings
    //     int flip=0;                         
    //     for(int i=newa.length()-1;i>=0;i--){           
    //         if(newc[i]=='0'){
    //             if(newa[i]=='0' && newb[i]=='1') flip++;
    //             else if(newa[i]=='1' && newb[i]=='0') flip++;
    //             else if(newa[i]=='1' && newb[i]=='1') flip+=2;
    //         }
    //         else{
    //             if(newa[i]=='0' && newb[i]=='0') flip++;
    //         }
    //     }
    //     return flip;
    // }
};