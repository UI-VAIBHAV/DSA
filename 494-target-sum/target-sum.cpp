class Solution {
public:
    int count(vector<int>nums,int target,int sum,int idx,vector<vector<int>>&dp,int num){
        if(idx==nums.size()) return sum==target;
        if(dp[idx][sum+num]!=-1) return dp[idx][sum+num];
        int plus = count(nums,target,sum+nums[idx],idx+1,dp,num);
        int minus = count(nums,target,sum-nums[idx],idx+1,dp,num);
        return dp[idx][sum+num] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0; 
        int num=0;
        for(int i:nums) num += i;
        vector<vector<int>>dp(nums.size()+1,vector<int>(2*num+1,-1));
        return count(nums,target,sum,0,dp,num);
    }
};