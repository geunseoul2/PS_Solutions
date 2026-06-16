class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>> row(9);
        vector<unordered_map<int,int>> col(9);
        vector<unordered_map<int,int>> square(9);


        //check row and collunm validate
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') continue;
                row[i][board[i][j]-48] += 1;
                col[j][board[i][j]-48] += 1;

                if(row[i][board[i][j]-48] > 1 || col[j][board[i][j]-48] > 1) return false;
            }
        }

        //check 9 squares.
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') continue;
                square[(i/3)*3+(j/3)][board[i][j]-48] += 1;
                if(square[(i/3)*3+(j/3)][board[i][j]-48] > 1) return false;
            }
        }

        return true;
    }
};
