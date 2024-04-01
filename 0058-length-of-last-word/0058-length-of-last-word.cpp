class Solution {
public:
    int lengthOfLastWord(string s) {
        int length=s.size(), count=0;
        for(int i=length-1;i>=0;i--){
            if(s[i]==' ' && count==0) continue;
            if(s[i]==' ' && count!=0 ) return count;
            if(s[i]!=' ') count++;
        }
        return count;
    }
};