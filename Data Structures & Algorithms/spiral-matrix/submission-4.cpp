class Solution {
public:
    void dfsSpiral(vector<vector<int>>& matrix, int top, int bottom, int left, int right, vector<int>& result) {
        // Base case: If boundaries cross, we are done
        if (top > bottom || left > right) return;

        // 1. Move RIGHT along the current top row
        for (int c = left; c <= right; ++c) {
            result.push_back(matrix[top][c]);
        }
        // We finished the top row, so push the top boundary down
        top++; 

        // 2. Move DOWN along the current right column
        for (int r = top; r <= bottom; ++r) {
            result.push_back(matrix[r][right]);
        }
        // We finished the right column, so pull the right boundary left
        right--; 

        // 3. Move LEFT along the current bottom row (if it still exists)
        if (top <= bottom) {
            for (int c = right; c >= left; --c) {
                result.push_back(matrix[bottom][c]);
            }
            // We finished the bottom row, so pull the bottom boundary up
            bottom--; 
        }

        // 4. Move UP along the current left column (if it still exists)
        if (left <= right) {
            for (int r = bottom; r >= top; --r) {
                result.push_back(matrix[r][left]);
            }
            // CRITICAL STEP: We finished the upward move, so push the left boundary right.
            // This prevents us from hitting matrix[0][0] or any already visited outer layer!
            left++; 
        }

        // Move to the next inner layer right side again by recursing
        dfsSpiral(matrix, top, bottom, left, right, result);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Initialize the 4 boundaries
        int top = 0;
        int bottom = rows - 1;
        int left = 0;
        int right = cols - 1;

        // Start the recursive layer-by-layer traversal
        dfsSpiral(matrix, top, bottom, left, right, result);

        return result;
    }
};