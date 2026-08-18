class Solution {
public:
    int count(string &s,string &t,vector<vector<int>>&dp,int i,int j){
        if(i>=s.size() || j>=t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = 1+count(s,t,dp,i+1,j+1);
        }
        int take = count(s,t,dp,i+1,j);
        int skip = count(s,t,dp,i,j+1);
        return dp[i][j] = max(take,skip);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return count(text1,text2,dp,0,0);
    }
};