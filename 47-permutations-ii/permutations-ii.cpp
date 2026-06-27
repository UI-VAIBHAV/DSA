class Solution {
public:
    void permute(vector<int>nums,vector<vector<int>>&ans,int idx,int n){
        vector<bool>used(21,0);
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            if(!used[nums[i]+10]){
                swap(nums[i],nums[idx]);
                permute(nums,ans,idx+1,n);
                swap(nums[i],nums[idx]);
                used[nums[i]+10] = 1;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        permute(nums,ans,0,n);
        return ans;
    }
};