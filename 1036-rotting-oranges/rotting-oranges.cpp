class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2) q.push(make_pair(i,j));
            }
        }
        int ans=0;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(i>0){
                    if(grid[i-1][j]==1){
                        grid[i-1][j] = 2;
                        q.push(make_pair(i-1,j));
                    }
                }
                if(j>0){
                    if(grid[i][j-1]==1){
                        grid[i][j-1] = 2;
                        q.push(make_pair(i,j-1));
                    }
                }
                if(i<grid.size()-1){
                    if(grid[i+1][j]==1){
                        grid[i+1][j] = 2;
                        q.push(make_pair(i+1,j));
                    }
                }
                if(j<grid[0].size()-1){
                    if(grid[i][j+1]==1){
                        grid[i][j+1] = 2;
                        q.push(make_pair(i,j+1));
                    }
                }
            }
            ans++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans==0?0:ans-1;
    }
};