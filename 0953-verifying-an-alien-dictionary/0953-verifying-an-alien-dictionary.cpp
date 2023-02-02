class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {

        // map which stores the order of the alien language 
        int j=0;
        map<char,int> mp;
        for( auto &it : order ) mp[it] = j++;

        // check for lexicographical order 
        for( int i=1 ; i<words.size() ; i++ ){

            bool flag = false ;
            string first = words[i-1];
            string second = words[i];

            int minLen = min(first.size(), second.size());

            for( int j=0 ; j<minLen ; j++ ){

                // words = ["hello","leetcode"]
                if( mp[first[j]] < mp[second[j]] ) {
                    flag = true ;
                    break;
                }

                // words = ["word","world","row"]
                if( mp[first[j]] > mp[second[j]] ) return false ;
            }

            // words = ["apple","app"]
            if( !flag && first.size() > second.size() ) return false ;
        }

        return true;
    }
};