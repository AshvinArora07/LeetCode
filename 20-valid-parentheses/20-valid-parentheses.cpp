class Solution {
public:
     bool isbalanced(char op, char cb){
            if(op=='{'&&cb=='}')
                return true;
            if(op=='['&&cb==']')
                return true;
            if(op=='('&&cb==')')
                return true;
            return false;
            
            
        }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
                st.push(s[i]);
            else{
                if(st.empty())
                    return false;
                else if(!isbalanced(st.top(),s[i]))
                    return false;
                st.pop();
            }
        }
        return st.size()==0;
    }
};