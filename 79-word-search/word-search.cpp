class Solution {
public: 
    bool check(vector<vector<char>>& board,string & word,int idx,int i,int j,int m,int n){
        if(idx==word.size()) return 1;
        if(i<0 || j<0 || i>=m || j>=n || board[i][j]!=word[idx]) return 0;
        char temp = board[i][j];
        board[i][j] = '$';
        bool ans =  check(board,word,idx+1,i+1,j,m,n)|| check(board,word,idx+1,i,j+1,m,n) || check(board,word,idx+1,i-1,j,m,n)|| check(board,word,idx+1,i,j-1,m,n);
        board[i][j] = temp;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(check(board,word,0,i,j,m,n)) return 1;
            }
        }
        return 0;
    }
};