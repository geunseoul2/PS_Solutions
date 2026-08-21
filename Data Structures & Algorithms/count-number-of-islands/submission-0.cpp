class Solution {
public:
    int row;
    int col;

    int numIslands(vector<vector<char>>& grid) {
        row = grid[0].size();
        col = grid.size();
        int ans = 0;
        
        for(int i=0; i<col; i++) {
            for(int j=0; j<row; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    checkIsland(grid,i,j);
                }
            }
        }

        return ans;
    }

    void checkIsland(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= col || j >= row) return;

        if(grid[i][j] == '1'){
            grid[i][j] = '2';
            checkIsland(grid,i-1,j);
            checkIsland(grid,i+1,j);
            checkIsland(grid,i,j-1);
            checkIsland(grid,i,j+1);
        }
        

        return;
    }
};
