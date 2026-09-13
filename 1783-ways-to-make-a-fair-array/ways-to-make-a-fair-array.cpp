class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int total_even=0,total_odd=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i%2==0) total_even += nums[i];
            else total_odd += nums[i];
        }
        int left_even=0,left_odd=0,ans=0;
        for(int i=0;i<n;i++){
            if(i%2==0) total_even -= nums[i];
            else total_odd -= nums[i];
            int new_even = left_even+total_odd;
            int new_odd = left_odd+total_even;
            if(new_even==new_odd) ans++;
            if(i%2==0) left_even += nums[i];
            else left_odd += nums[i];
        }
        return ans;
    }
};