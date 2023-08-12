class Solution {
public:
    bool isvowel(char x){
        if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U') return true;
    else return false;
}
    string reverseVowels(string s) {
        int start=0;
        int end=s.length()-1;
        while(start<end){
            if(isvowel(s[start]) && isvowel(s[end])){
                swap(s[start],s[end]);
                start++;
                end--;
                continue;
            }
            else if(isvowel(s[start]) && !isvowel(s[end])){
                end--;
                continue;
            }
            else if(!isvowel(s[start]) && isvowel(s[end])){
                start++;
                continue;
            }
            start++,end--;
        }
        return s;
    }
};
