class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int result;
        sort(nums.begin(),nums.end());
        int result1 ;
        result1 = nums[0]*nums[1]*nums[n-1];
        result = nums[n-3]*nums[n-2]*nums[n-1];
        if(result1>result){
            return result1;
        }
        return result;
    }
};