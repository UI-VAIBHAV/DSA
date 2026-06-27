class Solution {
public:
    int assign(vector<int>&nums,int target,int sum,int idx){
        if(idx==nums.size()){
            if(target==sum) return 1;
            return 0;
        }
        int plus = assign(nums,target,sum+nums[idx],idx+1);
        int minus = assign(nums,target,sum-nums[idx],idx+1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        return assign(nums,target,sum,0);
    }
};