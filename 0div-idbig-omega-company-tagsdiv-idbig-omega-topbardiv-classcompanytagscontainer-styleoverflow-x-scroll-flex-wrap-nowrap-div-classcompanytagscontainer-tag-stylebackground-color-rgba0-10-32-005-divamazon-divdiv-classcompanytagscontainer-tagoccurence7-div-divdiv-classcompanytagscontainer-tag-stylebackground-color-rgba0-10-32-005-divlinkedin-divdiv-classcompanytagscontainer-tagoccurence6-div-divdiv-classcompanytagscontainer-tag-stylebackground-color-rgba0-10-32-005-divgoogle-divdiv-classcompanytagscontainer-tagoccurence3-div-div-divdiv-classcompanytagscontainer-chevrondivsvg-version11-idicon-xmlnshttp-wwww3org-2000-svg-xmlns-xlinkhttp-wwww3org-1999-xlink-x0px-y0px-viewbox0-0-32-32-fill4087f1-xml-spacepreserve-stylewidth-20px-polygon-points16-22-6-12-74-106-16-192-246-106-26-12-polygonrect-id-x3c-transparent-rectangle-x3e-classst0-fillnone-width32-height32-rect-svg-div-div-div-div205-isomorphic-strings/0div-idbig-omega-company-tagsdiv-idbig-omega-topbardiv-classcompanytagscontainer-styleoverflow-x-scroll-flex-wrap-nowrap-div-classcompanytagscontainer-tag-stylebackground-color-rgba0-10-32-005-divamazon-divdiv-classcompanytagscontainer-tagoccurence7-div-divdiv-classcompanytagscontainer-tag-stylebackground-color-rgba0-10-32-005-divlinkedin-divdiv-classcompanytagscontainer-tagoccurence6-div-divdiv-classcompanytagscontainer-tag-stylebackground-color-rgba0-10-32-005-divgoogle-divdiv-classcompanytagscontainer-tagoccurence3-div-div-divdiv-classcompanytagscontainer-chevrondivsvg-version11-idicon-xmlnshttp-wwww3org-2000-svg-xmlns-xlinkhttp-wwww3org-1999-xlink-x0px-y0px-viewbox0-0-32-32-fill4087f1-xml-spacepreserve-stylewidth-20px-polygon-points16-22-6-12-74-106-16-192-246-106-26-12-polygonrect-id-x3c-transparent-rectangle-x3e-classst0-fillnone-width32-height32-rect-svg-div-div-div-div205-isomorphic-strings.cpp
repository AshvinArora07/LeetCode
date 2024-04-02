class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char, char> mappingStoT;
        unordered_map<char, char> mappingTtoS;
        int n=s.length();
        for(int i=0;i<n;i++){
            char schar=s[i];
            char tchar=t[i];
            
            if(!mappingStoT.count(schar))
                mappingStoT[schar]=tchar;
            if(!mappingTtoS.count(tchar))//if there is duplicacy , the count will increase representing one ore more value being maped with same schar.
                mappingTtoS[tchar]=schar;
            
            if(mappingStoT[schar]!=tchar || mappingTtoS[tchar]!=schar)
                return false;
        }
        return true;
    }
    
};