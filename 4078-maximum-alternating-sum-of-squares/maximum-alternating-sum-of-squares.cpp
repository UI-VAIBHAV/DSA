class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int start=0,end;
        if(nums.size()%2==0) end=nums.size()-1;
        else end = nums.size()-2;
        while(start<end){
            swap(nums[start],nums[end]);
            start += 2;
            end -= 2;
        }
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0) ans += nums[i]*nums[i];
            else ans -= nums[i]*nums[i];
        }
        return ans;
    }
};