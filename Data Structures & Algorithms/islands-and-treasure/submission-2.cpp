class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) return;
        int cols = grid[0].size();

        // Queue to store coordinates for multi-source BFS
        queue<pair<int, int>> q;

        // Step 1: Find all chests (0) and add them to the queue as starting points
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        // Direction vectors for moving up, down, left, and right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 2: Process the queue layer by layer
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                // Check boundaries and ensure the neighbor is an unvisited empty room (INF)
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == INT_MAX) {
                    // Update distance: neighbor's distance is current room's distance + 1
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
