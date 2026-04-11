class Solution {
public:
    int row[8] = {1,-1,0,0,1,1,-1,-1};
    int col[8] = {0,0,1,-1,1,-1,1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        if(grid.size() == 1) return 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1;
        int step=1;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0;k<8;k++){
                    int new_i = i+row[k];
                    int new_j = j+col[k];
                    if(new_i>=0 && new_i<grid.size() && new_j>=0 && new_j<grid[0].size()&& !grid[new_i][new_j]){
                        if(new_i==grid.size()-1 && new_j==grid[0].size()-1) return step+1;
                        grid[new_i][new_j] = 1;
                        q.push({new_i,new_j});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};