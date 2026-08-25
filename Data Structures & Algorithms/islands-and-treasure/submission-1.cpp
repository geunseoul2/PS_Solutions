class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        for(int i=0; i<grid.size();i++) {
            for(int j=0; j<grid[0].size();j++) {
                vector<vector<bool>> checked(grid.size(),vector<bool>(grid[0].size(),false));
                if(grid[i][j] == 0) checkPath(grid,i,j,checked);
            }
        }

    }

    void checkPath(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& checked) {
        for(int k=0; k<4; k++) {
            int ni = i+dy[k];
            int nj = j+dx[k];
            if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size() || grid[ni][nj] == -1 || checked[ni][nj]) continue;

            checked[ni][nj] = true;
            grid[ni][nj] = min(grid[ni][nj], grid[i][j]+1);
            checkPath(grid,ni,nj,checked);
            checked[ni][nj] = false;
        }
    }
};
