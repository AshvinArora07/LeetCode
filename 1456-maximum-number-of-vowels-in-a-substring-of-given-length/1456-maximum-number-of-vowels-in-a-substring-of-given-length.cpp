class Solution {
public:
    
    bool isvowel(char c){
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
    }
    
    int maxVowels(string s, int k) {
        int res=0,len=0,i=0,j=0,ctv=0;
        int n=s.size();
        while(j<n){
            if(isvowel(s[j]))
                ctv++;
        len++;
        if(len>k){
            if(isvowel(s[i]))
                ctv--;
            i++;
        }
            res=max(res,ctv);
            j++;
        }
        return res;
    }
};