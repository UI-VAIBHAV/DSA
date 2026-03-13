class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n==0) return "";
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<n;j++){
                if(i==strs[j].size() || strs[0][i]!=strs[j][i]) return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};