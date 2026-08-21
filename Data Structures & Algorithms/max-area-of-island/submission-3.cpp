class Solution {
public:
    int res = 0;
    int row, col;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid[0].size();
        col = grid.size();

        for(int i=0; i<col; i++) {
            for(int j=0; j<row; j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    checkIsland(grid,i,j,area);
                }
            }
        }

        return res;
    }

    void checkIsland(vector<vector<int>>& grid, int i, int j, int& area) {
        if(i < 0 || j < 0 || i >= col || j >= row) return;

        if(grid[i][j] == 1){
            grid[i][j] = 0;
            area++;
            checkIsland(grid,i-1,j,area);
            checkIsland(grid,i+1,j,area);
            checkIsland(grid,i,j-1,area);
            checkIsland(grid,i,j+1,area);
        }
        res = max(res,area);
        

        return;
    }
};
