class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0; i<m;i++) {
            for(int j=0; j<n;j++) {
                if(grid[i][j] == 0) q.push({i, j});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dy[k];
                int nc = c + dx[k];

                // 범위를 벗어나거나, 벽(-1)이거나, 이미 더 짧거나 같은 거리로 방문한 경우 건너뜀
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] == -1) {
                    continue;
                }

                // 아직 방문하지 않은 빈 공간(2147483647 / INF)인 경우 최단 거리 갱신
                if (grid[nr][nc] > grid[r][c] + 1) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};