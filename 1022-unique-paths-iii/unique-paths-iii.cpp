class Solution {
public:
    int m,n;
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    int res=0;
    void check(vector<vector<int>>& grid,int i,int j,int path,int count){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==-1) return ;
        if(grid[i][j]==2){
            if(count==path) res++;
            return;
        }
        grid[i][j] = -1;
        for(int k=0;k<4;k++){
            int newi = i+row[k];
            int newj = j+col[k];
            check(grid,newi,newj,path,count+1);
        }
        grid[i][j] = 0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int path=0,i_idx=-1,j_idx=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    path++;
                }
                else if(grid[i][j]==1){
                    i_idx = i;
                    j_idx=j;
                    path++;
                }
            }
        }
        check(grid,i_idx,j_idx,path,0);
        return res;
    }
};