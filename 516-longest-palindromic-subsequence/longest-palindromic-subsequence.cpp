class Solution {
public:
    int count(string &s,vector<vector<int>>&dp,int idx,int prev){
        if(idx>prev) return 0;
        if(idx==prev) return 1;
        if(dp[idx][prev]!=-1) return dp[idx][prev];
        if(s[idx]==s[prev]) return dp[idx][prev] = 2 + count(s,dp,idx+1,prev-1);
        return dp[idx][prev] = max(count(s,dp,idx+1,prev),count(s,dp,idx,prev-1));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return count(s,dp,0,n-1);
    }
};