class Solution {
private:
    // Helper function to perform DFS
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Base cases: Check out-of-bounds or if we hit water ('0')
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }

        // "Sink" the current piece of land so we don't visit it again
        grid[r][c] = '0';

        // Recursively explore all 4 directions (up, down, left, right)
        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // Handle empty grid edge case
        if (grid.empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int num_islands = 0;

        // Iterate through every cell in the grid
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If we find land ('1'), it's a new island
                if (grid[r][c] == '1') {
                    num_islands++;
                    dfs(grid, r, c); // Sink this entire island
                }
            }
        }

        return num_islands;
    }
};