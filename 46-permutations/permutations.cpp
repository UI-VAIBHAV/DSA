class Solution {
public:
    void permut(vector<int>nums,vector<vector<int>>&ans,int idx,int n){
        if(idx==n){
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<n;i++){
            swap(nums[i],nums[idx]);
            permut(nums,ans,idx+1,n);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        permut(nums,ans,0,n);
        return ans;
    }
};