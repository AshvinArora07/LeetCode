class Solution {
public:
    int partitionString(string s) {
        int count=1;
        set<char> st;// Using set to keep a track of duplicate elements and to erase them for                              unique substring
        for(int i=0;i<s.size();i++){
            if(st.find(s[i])!=st.end()){
                count++;
                st.clear();
                st.insert(s[i]);
            }
            else
                st.insert(s[i]);
        }
        return count;
    }
};