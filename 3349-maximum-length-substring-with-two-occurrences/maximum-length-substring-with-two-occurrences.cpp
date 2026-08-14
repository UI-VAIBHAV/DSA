class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int start=0,end=0,ans=0;
        while(end<s.size()){
            mp[s[end]]++;
            while(mp[s[end]]>2){
                mp[s[start]]--;
                start++;
            }
            ans = max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};