class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int end,start=0;
        char newchar;
        int length=0;
        map<char,int> m;
        for(end=0;end<s.length();end++){
            newchar=s[end];
            if(m.find(s[end])!=m.end())
                start = max(start,m.find(newchar)->second+1);
            m[newchar]=end;
            length=max(length,end-start+1);
        }
        return length;
    }
};