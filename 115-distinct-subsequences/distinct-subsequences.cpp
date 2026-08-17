class Solution {
public:
    int count(string &s,string &t,vector<vector<int>>&dp,int i,int j){
        if(j>=t.size()) return 1;
        if(i>=s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            int take = count(s,t,dp,i+1,j+1);
            int skip = count(s,t,dp,i+1,j);
            return dp[i][j] = take+skip;
        }
        return dp[i][j] = count(s,t,dp,i+1,j);
    }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m<n) return 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return count(s,t,dp,0,0);
    }
};