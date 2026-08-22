class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> available(n,0);
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        
        backtrack(0,n,board,ans);

        return ans;
    }
    
    void backtrack(int row,int n, vector<string>& board, vector<vector<string>>& ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int i=0; i<n; i++) {  
            if(check(row,i,board)) {
                board[row][i] = 'Q';
                backtrack(row+1,n,board,ans);
                board[row][i] = '.';
            }
        }
    }

    bool check(int r, int c, vector<string>& board) {
        for (int i = r - 1; i >= 0; i--) { //on the bottom
            if (board[i][c] == 'Q') return false;
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) { //on the right diag
            if (board[i][j] == 'Q') return false;
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < board.size(); i--, j++) { //on the left diag
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};
