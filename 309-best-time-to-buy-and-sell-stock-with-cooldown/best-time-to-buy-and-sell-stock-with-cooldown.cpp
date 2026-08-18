class Solution {
public:
    int count(vector<int>&arr,vector<vector<int>>&dp,int i,int check){
        if(i>= arr.size()) return 0;
        if(dp[i][check]!=-1) return dp[i][check];
        int take=0;
        if(check==0){
            take = -arr[i] + count(arr,dp,i+1,1);
        }
        else if(check==1){
            take = arr[i] + count(arr,dp,i+1,2);
        }
        else take = count(arr,dp,i+1,0);
        int skip = count(arr,dp,i+1,check);
        return dp[i][check] = max(take,skip);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return count(prices,dp,0,0);
    }
};