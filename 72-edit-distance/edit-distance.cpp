class Solution {
public:
    int count(string  &s,string &t,vector<vector<int>>&dp,int i,int j){
        if(i>=s.size()) return t.size()-j;
        if(j>=t.size()) return s.size()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j] = count(s,t,dp,i+1,j+1);
        }
        int insert = 1+count(s,t,dp,i,j+1);
        int replace = 1+count(s,t,dp,i+1,j+1);
        int del = 1+count(s,t,dp,i+1,j);
        return dp[i][j] = min({insert,replace,del});
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return count(word1,word2,dp,0,0);
    }
};