class Solution {
public:
    // Fixed: Changed 'char' to 'grid'
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols){
        // base case for the recursion . checking that there is water or not 
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') return;

        // now we have to mark the current island as the visited or kind of sinked in the water so we not visit that thing repeatedly .
        grid[r][c] = '0';

        // we have to recursively explore all the 4 directions
        dfs(grid, r-1, c, rows, cols);
        dfs(grid, r+1, c, rows, cols);
        dfs(grid, r, c-1, rows, cols);
        dfs(grid, r, c+1, rows, cols);
    }

    int numIslands(vector<vector<char>>& grid) {
        // Fixed: Added parentheses to empty()
        if(grid.empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int num_islands = 0;

        // Fixed: Changed ++r to ++i
        for(int i = 0 ; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                // Fixed: Removed semicolon and added curly braces
                if(grid[i][j] == '1') {
                    // Fixed: Changed to num_islands (plural)
                    num_islands++;
                    dfs(grid, i, j, rows, cols);
                }
            }
        }
        return num_islands;
    }
};