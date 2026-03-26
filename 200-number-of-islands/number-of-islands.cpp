class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        queue<pair<int,int>>q;
        int m = grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    q.push(make_pair(i,j));
                    grid[i][j] = '0';
                    while(!q.empty()){
                        int i = q.front().first;
                        int j = q.front().second;
                        q.pop();
                        if(i>0){
                            if(grid[i-1][j]=='1'){
                                grid[i-1][j] = '0';
                                q.push(make_pair(i-1,j));
                            }
                        }
                        if(j>0){
                            if(grid[i][j-1]=='1'){
                                grid[i][j-1] = '0';
                                q.push(make_pair(i,j-1));
                            }
                        }
                        if(i<grid.size()-1){
                            if(grid[i+1][j]=='1'){
                                grid[i+1][j] ='0';
                                q.push(make_pair(i+1,j));
                            }
                        }
                        if(j<grid[0].size()-1){
                            if(grid[i][j+1]=='1'){
                                grid[i][j+1] = '0';
                                q.push(make_pair(i,j+1));
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};