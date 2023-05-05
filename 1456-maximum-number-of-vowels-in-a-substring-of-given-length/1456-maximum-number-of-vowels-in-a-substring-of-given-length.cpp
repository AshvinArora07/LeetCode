class Solution {
public:  
    bool isvowel(char c){
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
            return 1;
        return 0;
    }
    
    int maxVowels(string s, int k) {
        int n=s.size();
        /* 1 Solution
        int res=0,len=0,i=0,j=0,ctv=0;
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
        */
        // Sliding Window Approach
        int curr_vow=0, max_vow=0;
        for(int i=0;i<n;i++){
            curr_vow+=isvowel(s[i]);
            if(i>=k)
                curr_vow-=isvowel(s[i-k]);
            //because when we shift to the next window after length k we delete the vowel at i-k position which will not be included int the current window after moving from previous window
            max_vow=max(max_vow,curr_vow);
        }
        return max_vow;
    }
};