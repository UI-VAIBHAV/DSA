class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        s.erase(s.find_last_not_of(' ') + 1);
        int n = s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' ') return ans;
            else ans++;
        }
        return ans;
    }
};