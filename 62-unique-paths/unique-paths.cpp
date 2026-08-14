class Solution {
public:
    int count(vector<vector<int>>&dp,int m,int n,int i,int j){
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j] = count(dp,m,n,i+1,j) + count(dp,m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return count(dp,m,n,0,0);
    }
};