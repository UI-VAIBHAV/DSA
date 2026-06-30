class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mp;
        int start=0, ans=0, end=0;
        while(end<s.size()){
            mp[s[end]]++;
            while(mp.size() == 3) {
                ans += s.size() - end;
                mp[s[start]]--;
                if(mp[s[start]] == 0) mp.erase(s[start]);
                start++;
            }
            end++;
        }
        return ans;
    }
};