#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Base cases: check bounds or if we hit water (0)
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) {
            return 0;
        }

        // Sink the land so we don't visit it again
        grid[r][c] = 0;

        // Count this cell (1) + look in all 4 directions
        return 1 + dfs(grid, r - 1, c) 
                 + dfs(grid, r + 1, c) 
                 + dfs(grid, r, c - 1) 
                 + dfs(grid, r, c + 1);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int max_area = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // If we find land (1), calculate its total area
                if (grid[r][c] == 1) {
                    int current_area = dfs(grid, r, c);
                    max_area = max(max_area, current_area);
                }
            }
        }

        return max_area;
    }
};