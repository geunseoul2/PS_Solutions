class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int x_size;
    int y_size;

    bool exist(vector<vector<char>>& board, string word) {
        x_size = board[0].size();
        y_size = board.size();
        vector<vector<bool>> used(y_size, vector<bool>(x_size, false));

        for(int i=0; i<y_size; i++) {
            for(int j=0; j<x_size; j++) {
                if(board[i][j] == word[0]) {
                    used[i][j] = true;
                    cout << word.substr(1) << endl;
                    bool res = backtrack(board,i,j,word.substr(1),used);
                    if(res) return res;
                    used[i][j] = false;
                }
            }
        }

        return false;
    }

    bool backtrack(vector<vector<char>>& board, int i, int j, string word, vector<vector<bool>> used){
        if(word.size() == 0) return true;

        for(int dir = 0; dir<4; dir++) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];

            if(ni >= 0 && ni < y_size && nj >= 0 && nj < x_size && !used[ni][nj] && board[ni][nj] == word[0]) {
                used[ni][nj] = true;
                bool res = backtrack(board,ni,nj,word.substr(1),used);
                if(res) return res;
                used[ni][nj] = false;
            }
        }

        return false;
    }
};
