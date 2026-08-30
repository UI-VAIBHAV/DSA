class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int max_idx = max_element(nums.begin(),nums.end())-nums.begin();
        int min_idx = min_element(nums.begin(),nums.end())-nums.begin();
        if(min_idx>max_idx) swap(min_idx,max_idx);
        int f_remove = max_idx+1;
        int b_remove = n-min_idx;
        int both_remove = (min_idx+1) + (n-max_idx);
        return min({f_remove,b_remove,both_remove});
    }
};