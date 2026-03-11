class Solution {
public:
    pair<long long,long long>path(int m,int n,int i,int j,vector<vector<int>>& grid,vector<vector<pair<long long,long long>>>&box){
        if(i==m-1 && j==n-1) return {grid[i][j],grid[i][j]};
        if(box[i][j]!=make_pair(-1,-1)) return box[i][j];
        long long maxval = LLONG_MIN,minval = LLONG_MAX;
        if(i+1<m){
            auto[downmax,downmin] = path(m,n,i+1,j,grid,box);
            maxval = max({maxval,grid[i][j]*downmax,grid[i][j]*downmin});
            minval = min({minval,grid[i][j]*downmin,grid[i][j]*downmax});
        }
        if(j+1<n){
            auto[rightmax,rightmin] = path(m,n,i,j+1,grid,box);
            maxval = max({maxval,grid[i][j]*rightmax,grid[i][j]*rightmin});
            minval = min({minval,grid[i][j]*rightmax,grid[i][j]*rightmin});
        }
        return box[i][j] = make_pair(maxval,minval);
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<pair<long long,long long>>> box(m, vector<pair<long long,long long>>(n, make_pair(-1,-1)));
        auto[maxpro,minpro] = path(m,n,0,0,grid,box);
        const int MOD = 1e9+7;
        return maxpro<0?-1:maxpro%MOD;
    }
};