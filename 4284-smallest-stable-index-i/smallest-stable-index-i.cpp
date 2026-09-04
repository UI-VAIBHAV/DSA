class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int min_val=INT_MAX,max_val=INT_MIN;
            for(int j=0;j<=i;j++) max_val = max(max_val,nums[j]);
            for(int j=i;j<nums.size();j++) min_val = min(min_val,nums[j]);
            if(max_val-min_val<=k) return i;
        }
        return -1;
    }
};