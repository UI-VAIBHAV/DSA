class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        queue<pair<int,int>>q;
        int m = grid.size();
        int n = grid[0].size();
        for(int j=0;j<grid[0].size();j++){
            if(grid[0][j]=='O'){
                grid[0][j] = 'T';
                q.push(make_pair(0,j));
            }
            if(grid[m-1][j]=='O'){
                grid[m-1][j] = 'T';
                q.push(make_pair(m-1,j));
            }
        }
        for(int i=1;i<grid.size();i++){
            if(grid[i][0]=='O'){
                grid[i][0] = 'T';
                q.push(make_pair(i,0));
            }
            if(grid[i][n-1]=='O'){
                grid[i][n-1] = 'T';
                q.push(make_pair(i,n-1));
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if(i>0 && grid[i-1][j]=='O'){
                grid[i-1][j] = 'T';
                q.push({i-1,j});
            }
            if(j>0 && grid[i][j-1]=='O'){
                grid[i][j-1] = 'T';
                q.push({i,j-1});
            }
            if(i<m-1 && grid[i+1][j]=='O'){
                grid[i+1][j] = 'T';
                q.push({i+1,j});
            }
            if(j<n-1 && grid[i][j+1]=='O'){
                grid[i][j+1] = 'T';
                q.push({i,j+1});
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='T') grid[i][j] = 'O';
                else grid[i][j] = 'X';
            }
        }
    }
};