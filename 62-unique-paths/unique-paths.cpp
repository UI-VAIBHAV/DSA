class Solution {
public:
    int paths(int m,int n,vector<vector<int>>&box,int i,int j){
        if(i==m-1 && j==n-1) return 1;
        if(i==m || j==n) return 0;
        if(box[i][j]!=-1) return box[i][j];
        int row = paths(m,n,box,i+1,j);
        int col = paths(m,n,box,i,j+1);
        return box[i][j] = row+col;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>box(m,vector<int>(n,-1));
        return paths(m,n,box,0,0);
    }
};