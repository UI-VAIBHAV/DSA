class Solution {
public:
    void sub(vector<int>nums,vector<int>temp,vector<vector<int>>&ans,int idx,int n,map<vector<int>,bool>&mp){
        if(idx==n){
            sort(temp.begin(),temp.end());
            if(!mp[temp]){
                ans.push_back(temp);
                mp[temp]=1;
            }
            return;
        }
        sub(nums,temp,ans,idx+1,n,mp);
        temp.push_back(nums[idx]);
        sub(nums,temp,ans,idx+1,n,mp);
        temp.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        int n = nums.size();
        map<vector<int>,bool>mp;
        sub(nums,temp,ans,0,n,mp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};