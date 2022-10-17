class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> freq(26);
        for(char& it:sentence) freq[it-'a']++;
        for(auto it:freq)
            if(it==0) return false;
        return true;
    }
};