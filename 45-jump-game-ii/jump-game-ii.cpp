class Solution {
public:
    int count(vector<int>&nums,vector<int>&dp,int n,int idx){
        if(idx>=n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans = INT_MAX;
        for(int i=1;i<=nums[idx];i++){
            if(idx+i<n){
                int jump = count(nums,dp,n,idx+i);
                if(jump!=INT_MAX) ans = min(ans,1+jump);
            }
        }
        return dp[idx] = ans;;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return count(nums,dp,n,0);
    }
};