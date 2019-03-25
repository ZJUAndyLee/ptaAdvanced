//用一个hash表一个个判断没什么高明之处

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> hash;
        for(int i=0;i<=9;i++){
            hash[i+'0']=0;
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]!='.'){
                    hash[board[i][j]]++;
                    if(hash[board[i][j]]==2) return false;
                }
            }
            hash.clear();
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[j][i]!='.'){
                   hash[board[j][i]]++;
                    if(hash[board[j][i]]==2) return false;
                }
            }
            hash.clear();
        }
        int ct=0;
        while(ct<9){
            int tmp1=ct%3;
            int tmp2=ct/3;
            for(int i=tmp1*3;i<tmp1*3+3;i++){
                for(int j=tmp2*3;j<tmp2*3+3;j++){
                    if(board[i][j]!='.') hash[board[i][j]]++;
                    if(hash[board[i][j]]==2) return false;
                }
            }
            hash.clear();
            ct++;
        }
        return true;
    }
};
