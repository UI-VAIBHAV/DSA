class Solution {
public:
    int count(vector<int>&nums,vector<vector<int>>&dp,int i,int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MIN;
        for(int k=i;k<=j;k++){
            int cost = nums[i-1]*nums[k]*nums[j+1] + count(nums,dp,i,k-1) + count(nums,dp,k+1,j);
            mini = max(cost,mini);
        }
        return dp[i][j] = mini;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return count(nums,dp,1,n);
    }
};