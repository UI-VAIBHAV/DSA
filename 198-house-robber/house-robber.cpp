class Solution {
public:
    int count(vector<int>&nums,vector<int>&dp,int idx){
        if(idx>=nums.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx] + count(nums,dp,idx+2);
        int skip = count(nums,dp,idx+1);
        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return count(nums,dp,0);
    }
};