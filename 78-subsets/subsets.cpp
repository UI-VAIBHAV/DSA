class Solution {
public:
    void sub(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int idx,int n){
        if(idx>=n){
            ans.push_back(temp);
            return;
        }
        sub(nums,ans,temp,idx+1,n);
        temp.push_back(nums[idx]);
        sub(nums,ans,temp,idx+1,n);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = nums.size();
        sub(nums,ans,temp,0,n);
        return ans;
    }
};