class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int c=grid.size();
        int r=grid[0].size();
        for(int i=1;i<c;i++){
            grid[i][0]+=grid[i-1][0];
        }
        for(int i=1;i<r;i++){
            grid[0][i]+=grid[0][i-1];
        }

        for(int i=1;i<c;i++){
            for(int j=1;j<r;j++){
                grid[i][j]+=(grid[i-1][j]<grid[i][j-1]) ? grid[i-1][j]:grid[i][j-1];
            }
        }

        return grid[c-1][r-1];
    }
};