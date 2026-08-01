class Solution {
public:
    int check(vector<int>&nums,int start,int end){
        if(start>end) return 0;
        if(start==end) return nums[start];
        int take = nums[start]+min(check(nums,start+2,end),check(nums,start+1,end-1));
        int skip = nums[end]+min(check(nums,start,end-2),check(nums,start+1,end-1));
        return max(take,skip);
    }
    bool predictTheWinner(vector<int>& nums) {
        int start=0,end=nums.size()-1;
        
        int sum1 = check(nums,start,end);
        int sum2=0,total_sum=0;
        for(int i:nums){
            total_sum += i;
        }
        sum2 = total_sum-sum1;
        return sum1>=sum2?1:0;
    }
};