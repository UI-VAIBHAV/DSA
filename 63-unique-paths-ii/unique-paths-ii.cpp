class Solution {
public:
    int path(int m,int n,int i,int j,vector<vector<int>> &box,vector<vector<int>>& obstacleGrid){
        
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i==m || j==n){
            return 0;
        }
        if(obstacleGrid[i][j]==1){
            return 0;
        }

        if(box[i][j]!=-1){
            return box[i][j];
        }

        int row = path(m,n,i+1,j,box,obstacleGrid);
        int col = path(m,n,i,j+1,box,obstacleGrid);
        box[i][j] = row+col;

        return box[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        vector<vector<int>>box(m,vector<int>(n,-1));
        return path(m,n,0,0,box,obstacleGrid);
    }
};