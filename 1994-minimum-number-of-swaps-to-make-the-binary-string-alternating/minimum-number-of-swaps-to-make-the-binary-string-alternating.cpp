class Solution {
public:
    int minSwaps(string s) {
        string s1="";
        string s2="";
        char c = '0';
        char d = '1';
        for(int i=0;i<s.size();i++){
            s1.push_back(c);
            s2.push_back(d);
            if(c=='0') c = '1';
            else c = '0';
            if(d=='1') d = '0';
            else d = '1';
        }
        unordered_map<char,int>mp;
        for(char c:s) mp[c]++;
        if(abs(mp['0']-mp['1'])>1) return -1;
        int ans1=0,ans2=0;
        for(int i=0;i<s.size();i++){
            if(s[i] != s1[i]) ans1++;
            if(s[i] != s2[i]) ans2++;
        }
        int ans=0;
        if(mp['0']>mp['1']) ans = ans1/2;
        else if(mp['1']>mp['0']) ans = ans2/2;
        else ans = min(ans1,ans2)/2;
        return ans;
    }
};