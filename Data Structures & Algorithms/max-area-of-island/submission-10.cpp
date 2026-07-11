class Solution {
public:
    

    // BUG: Look closely at the data type of the first parameter `grid`. 
    // It is defined as a 1D vector, but the input is a 2D vector.
    int dfs(vector<vector<int>>& grid,int r,int c) {
        int rows=grid.size();
        int cols=grid[0].size();
    
    if(r<0||r>=rows ||c<0 ||c>=cols || grid[r][c] == 0 ) return 0;

    
    grid[r][c] = 0;
    
    // BUG: Check your recursive calls. Your function definition above expects 
    // arguments for the grid, row, and col, but you are only passing two arguments here.
    return 1+ dfs(grid,r-1,c)+ dfs(grid,r+1,c)+ dfs(grid,r,c-1)+ dfs(grid,r,c+1) ; 
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        
        int rows=grid.size();
        int cols=grid[0].size();
        int maxarea=0;

        for(int r=0;r<rows;++r){
            for(int c=0;c<cols;++c){
                if(grid[r][c] == 1) {
                    maxarea = max (maxarea,dfs(grid,r,c));
                }
            }
        }
        return maxarea;
    }
};