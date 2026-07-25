class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int ans[m][n];

        if(obstacleGrid[0][0]) return 0;
        ans[0][0]=1;

        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0]){
                ans[i][0]=0;
            }else{
                ans[i][0]=ans[i-1][0];
            }
        }
        for(int j=1;j<n;j++){
            if(obstacleGrid[0][j]){
                ans[0][j]=0;
            }else{
                ans[0][j]=ans[0][j-1];
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]) ans[i][j]=0;
                else ans[i][j]=ans[i][j-1]+ans[i-1][j];
            }
        }

        return ans[m-1][n-1];
    }
};