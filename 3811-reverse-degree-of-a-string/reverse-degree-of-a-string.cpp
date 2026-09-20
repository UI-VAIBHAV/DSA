class Solution {
public:
    int reverseDegree(string s) {
        int ans=0,val=26;
        unordered_map<char,int>mp;
        for(char c='a';c<='z';c++){
            mp[c] = val;
            val--;
        }
        for(int i=0;i<s.size();i++){
            ans += mp[s[i]]*(i+1);
        }
        return ans;
    }
};