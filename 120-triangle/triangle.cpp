class Solution {
public:
    int count(vector<vector<int>>&arr,vector<vector<int>>&dp,int m,int n,int i,int j){
        if(i==m-1) return arr[i][j];
        if(dp[i][j]!=1e9) return dp[i][j];
        int right = count(arr,dp,m,n,i+1,j);
        int down = count(arr,dp,m,n,i+1,j+1);
        return dp[i][j] = arr[i][j] + min(right,down);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,1e9));
        return count(triangle,dp,m,n,0,0);
    }
};