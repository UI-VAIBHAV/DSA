class Solution {
public:
    int count(vector<int>&nums,vector<int>&dp,int idx,int n){
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx] + count(nums,dp,idx+2,n);
        int skip = count(nums,dp,idx+1,n);
        return dp[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        int take1 = count(nums,dp1,0,nums.size()-1);
        int take2 = count(nums,dp2,1,nums.size());
        return max(take1,take2);
    }
};