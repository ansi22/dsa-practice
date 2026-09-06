class Solution {
public:
    int dist[75][75][4][75];
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    int minCost(vector<vector<int>>& grid, int maxK) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) {
            return grid[0][0];
        }
        
        memset(dist, 0x3f, sizeof(dist));
        // Priority queue stores: {cost, x, y, direction, turns}
        priority_queue<tuple<int, int, int, int, int>, 
                       vector<tuple<int, int, int, int, int>>, 
                       greater<>> pq;

        // Initialize starting moves from (0,0)
        for (int d = 0; d < 4; d++) {
            int nx = dx[d], ny = dy[d];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                dist[nx][ny][d][0] = grid[0][0] + grid[nx][ny];
                pq.emplace(dist[nx][ny][d][0], nx, ny, d, 0);
            }
        }

        while (!pq.empty()) {
            auto [cost, x, y, dir, turns] = pq.top();
            pq.pop();

            if (x == m - 1 && y == n - 1) {
                return cost;
            }

            if (cost > dist[x][y][dir][turns]) continue;

            for (int p = 0; p < 4; p++) {
                // Prevent going backward (180-degree turn)
                if ((p + 2) % 4 == dir) continue;

                int nt = turns + (p != dir);
                if (nt > maxK) continue; // Compare against maxK parameter

                int nx = x + dx[p];
                int ny = y + dy[p];

                // Fixed boundary check variables (nx and ny instead of x and y)
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    if (cost + grid[nx][ny] < dist[nx][ny][p][nt]) {
                        dist[nx][ny][p][nt] = cost + grid[nx][ny];
                        pq.emplace(dist[nx][ny][p][nt], nx, ny, p, nt);
                    }
                }
            }
        }

        return -1;
    }
};