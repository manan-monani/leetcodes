class Solution {
public:
    vector<vector<int>> grid;
    // Updated to match the bool initialization below
    vector<vector<bool>> visited; 
    int rows, cols;

    int dfs(int r, int c) {
        // Base case: if we go out of bounds or hit water, it counts as 1 perimeter edge
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return 1;

        // If already visited land, it contributes 0 to the perimeter
        if (visited[r][c]) return 0;

        visited[r][c] = true;
        
        // Fixed: Changed 'i' and 'j' to 'r' and 'c'
        return dfs(r - 1, c) + dfs(r + 1, c) + dfs(r, c - 1) + dfs(r, c + 1); 
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid = grid;

        rows = grid.size();
        cols = grid[0].size();

        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));

        // Fixed: Added the missing outer loop for rows (i)
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Find the first piece of land and start DFS
                if (grid[i][j] == 1) {
                    return dfs(i, j); // The problem guarantees exactly one island
                }
            }
        }
        
        return 0;
    }
};