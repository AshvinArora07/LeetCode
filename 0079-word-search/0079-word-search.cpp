class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word=="") return true;
        for(int  i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==word[0]){
                    if(dfs(board,word,i,j))
                        return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>&board, string &word, int i, int j ){
        if(word.size()==0){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[i].size()||board[i][j]!=word[0])return false;
        char ch=board[i][j];
        board[i][j]='-';
        string str=word.substr(1);
        bool res=dfs(board, str,i,j+1)||dfs(board,str,i+1,j)||dfs(board,str,i-1,j)||dfs(board,str,i,j-1);
        board[i][j]=ch;
        return res;
    }
    
};