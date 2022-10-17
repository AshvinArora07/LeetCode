class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26);
        for(auto ch:sentence) freq[ch-'a']++;
        for(auto it:freq)
            if(it==0) return false;
        return true;
    }
};