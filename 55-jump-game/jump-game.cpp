class Solution {
public:
    bool check(vector<int>&nums,vector<int>&dp,int n,int idx){
        if(idx>=n-1) return 1;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            if(check(nums,dp,n,idx+i)) return dp[idx] = 1;
        }
        return dp[idx] =  0;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return check(nums,dp,n,0);    
    }
};