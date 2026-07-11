class Solution{
public:
int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    queue<pair<int, int>> q;
    int fresh_count = 0;
    int minutes = 0;
    
    // Step 1: Scan grid for rotten and fresh oranges
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 2) {
                q.push({r, c});
            } else if (grid[r][c] == 1) {
                fresh_count++;
            }
        }
    }
    
    if (fresh_count == 0) return 0;
    
    // Step 2: BFS Loop
    while (!q.empty() && fresh_count > 0) {
        minutes++;
        int current_level_size = q.size();
        
        for (int i = 0; i < current_level_size; ++i) {
            pair<int, int> curr = q.front();
            q.pop();
            int r = curr.first;
            int c = curr.second;
            
            // 1. Check UP (r - 1)
            if (r - 1 >= 0 && grid[r - 1][c] == 1) {
                grid[r - 1][c] = 2;
                fresh_count--;
                q.push({r - 1, c});
            }
            // 2. Check DOWN (r + 1)
            if (r + 1 < rows && grid[r + 1][c] == 1) {
                grid[r + 1][c] = 2;
                fresh_count--;
                q.push({r + 1, c});
            }
            // 3. Check LEFT (c - 1)
            if (c - 1 >= 0 && grid[r][c - 1] == 1) {
                grid[r][c - 1] = 2;
                fresh_count--;
                q.push({r, c - 1});
            }
            // 4. Check RIGHT (c + 1)
            if (c + 1 < cols && grid[r][c + 1] == 1) {
                grid[r][c + 1] = 2;
                fresh_count--;
                q.push({r, c + 1});
            }
        }
    }
    
    return (fresh_count == 0) ? minutes : -1;
}
};