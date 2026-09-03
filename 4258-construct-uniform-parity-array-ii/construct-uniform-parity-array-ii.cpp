class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int mini=INT_MAX;

        int even_count=0;
        int odd_count=0;
        for(int i=0;i<n;i++){
            mini=min(mini,nums1[i]);

            if(nums1[i]%2==0)   even_count++;
            if(nums1[i]%2==1)   odd_count++;
        }

        if(even_count==n || odd_count==n)   return true;

        return mini%2==1;
    }
};