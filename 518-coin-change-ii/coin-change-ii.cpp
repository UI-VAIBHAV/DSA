class Solution {
public:
    int count(vector<int>&coins,int amount,vector<vector<int>>&dp,int idx,int n){
        if(idx>=n || amount<0) return 0;
        if(amount==0) return 1;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int take = count(coins,amount-coins[idx],dp,idx,n);
        int skip = count(coins,amount,dp,idx+1,n);
        return dp[idx][amount] = take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        sort(coins.begin(),coins.end());
        return count(coins,amount,dp,0,n);
    }
};