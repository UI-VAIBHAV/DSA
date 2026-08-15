class Solution {
public:
    int count(vector<int>&coins,int amount,int idx,vector<vector<int>>&dp){
        if(idx<0 || amount<0) return 1e9;
        if(amount==0) return 0;
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        int take = 1+count(coins,amount-coins[idx],idx,dp);
        int skip = count(coins,amount,idx-1,dp);
        return dp[idx][amount] = min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans =  count(coins,amount,n-1,dp);
        return ans==1e9?-1:ans;
    }
};