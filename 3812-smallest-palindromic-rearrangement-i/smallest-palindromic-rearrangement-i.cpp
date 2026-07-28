class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>mp(26,0);
        for(char c:s){
            mp[c-'a']++;
        }
        string ans = s;
        int start=0,end=s.size()-1;
        for(int i=0;i<26;i++){
            while(mp[i]>=2){
                ans[start] = 'a'+i;
                ans[end] = 'a'+i;
                start++;
                end--;
                mp[i] -= 2;
            }
            if(mp[i]==1){
                ans[start] = 'a'+i;
            }
        }
        return ans;
    }
};