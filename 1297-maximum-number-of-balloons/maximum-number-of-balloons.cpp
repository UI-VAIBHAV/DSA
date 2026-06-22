class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>mp;
        for(char c:text) mp[c]++;
        if(!mp['b']|| !mp['a']|| mp['l'] <= 1 || mp['o']<=1 || !mp['n']) return 0;
        int ans=INT_MAX;
        ans = min(ans,mp['b']);
        ans = min(ans,mp['a']);
        ans = min(ans,mp['l']/2);
        ans = min(ans,mp['o']/2);
        ans = min(ans,mp['n']);
        return ans;
    }
};