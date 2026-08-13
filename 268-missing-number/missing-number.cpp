class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (n*(n+1))/2;
        int ans=0;
        for(int i:nums) ans+= i;
        return sum-ans;
    }
};