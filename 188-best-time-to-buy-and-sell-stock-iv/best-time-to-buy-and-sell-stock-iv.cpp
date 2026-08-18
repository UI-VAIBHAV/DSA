class Solution {
public:
    int count(vector<int>&arr,int val,vector<vector<vector<int>>>&dp,int i,bool check,int k){
        if(val>=k || i>=arr.size()) return 0;
        if(dp[i][val][check]!=-1) return dp[i][val][check];
        int take=0;
        if(!check){
            take = -arr[i]+count(arr,val,dp,i+1,!check,k);
        }
        else take = arr[i] + count(arr,val+1,dp,i+1,!check,k);
        int skip = count(arr,val,dp,i+1,check,k);
        return dp[i][val][check] = max(take,skip);
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return count(prices,0,dp,0,0,k);
    }
};