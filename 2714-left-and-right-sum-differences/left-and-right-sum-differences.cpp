class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftsum(n,0);
        vector<int>rightsum(n,0);
        int val=0;
        for(int i=0;i<n;i++){
            leftsum[i] = val;
            val += nums[i];
        }
        val=0;
        for(int i=n-1;i>=0;i--){
            rightsum[i] = val;
            val += nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i] = abs(leftsum[i]-rightsum[i]);
        }
        return nums;
    }
};