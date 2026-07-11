class Solution {
public:

    void dfs(vector<vector<char>>& grid , int r, int c){
        int rows=grid.size() , cols=grid[0].size();

        // check the base case firstly 
        if(r<0||c<0 ||r>=rows ||c>=cols ||grid[r][c]=='0') return;

        //  now sink the island so we dont count it again
        grid[r][c] = '0';
        // and perform the dfs
        dfs(grid,r-1,c);
        dfs(grid,r+1,c);
        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
    }



    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int rows=grid.size() , cols=grid[0].size();
        int num_islands=0;

        for(int r=0;r<rows;r++){
            for(int c=0;c<cols;c++){
                if(grid[r][c] == '1'){
                    // sink that island fully in the water and increase the count 
                    dfs(grid,r,c);
                    num_islands++;

                }
            }
        }
        return num_islands;
    }
};
