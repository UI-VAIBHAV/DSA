class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=INT_MIN;
        int val=0;
        for(int i:gain){
            ans = max(ans,val);
            val += i;
        }
        ans = max(ans,val);
        return ans;
    }
};