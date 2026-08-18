class Solution {
public:
    int count(vector<int>&arr,vector<vector<int>>&dp,int i,bool check,int fee){
        if(i>=arr.size()) return 0;
        if(dp[i][check]!=-1) return dp[i][check];
        int take=0;
        if(!check){
            take = -arr[i] + count(arr,dp,i+1,1,fee);
        }
        else take = arr[i] + count(arr,dp,i+1,0,fee) -fee ;
        int skip = count(arr,dp,i+1,check,fee);
        return dp[i][check] = max(take,skip);
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return count(prices,dp,0,0,fee);
    }
};