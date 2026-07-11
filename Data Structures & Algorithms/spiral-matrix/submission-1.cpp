class Solution {
public:
    // Direction vectors: Right, Down, Left, Up
    // We order them this way to naturally follow the spiral path
    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    void dfs(vector<vector<int>>& matrix, int r, int c, int dir, vector<vector<bool>>& visited, vector<int>& result) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // 1. Visit the current cell
        visited[r][c] = true;
        result.push_back(matrix[r][c]);

        // 2. Try to continue moving in the *same* direction first
        for (int i = 0; i < 4; ++i) {
            // Formula to turn 90 degrees clockwise if the current direction is blocked
            int nextDir = (dir + i) % 4; 
            
            int nextR = r + dr[nextDir];
            int nextC = c + dc[nextDir];

            // Check if the next cell is valid and unvisited
            if (nextR >= 0 && nextR < rows && nextC >= 0 && nextC < cols && !visited[nextR][nextC]) {
                dfs(matrix, nextR, nextC, nextDir, visited, result);
                break; // Once the deeper DFS path completes, we are done!
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int rows = matrix.size();
        int cols = matrix[0].size();
        
        // Keeps track of cells we've already added to our spiral
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // Start DFS from top-left (0,0) moving 'Right' (direction index 0)
        dfs(matrix, 0, 0, 0, visited, result);

        return result;
    }
};