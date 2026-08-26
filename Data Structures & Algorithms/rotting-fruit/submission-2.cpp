class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, time = 0;
        int m = grid.size();
        int n = grid[0].size();
        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }
        if(fresh == 0) return 0;
        
        while(!q.empty()) {
            int size = q.size();

            for(int i=0; i<size; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int nr = r + dy[k];
                    int nc = c + dx[k];

                    if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                    
                    if(grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }

            time++;
        }

        if(fresh == 0) return time-1;
        else return -1;
    }
};
