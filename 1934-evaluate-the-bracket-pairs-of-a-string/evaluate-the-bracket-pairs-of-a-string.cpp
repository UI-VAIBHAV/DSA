class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &it:knowledge){
            string s1 = it[0];
            string s2 = it[1];
            mp[s1] = s2;
        }
        string res="";
        int n = s.size();
        for (int i = 0; i < n; ) {
            if (s[i] == '(') {
                int j = i + 1;
                while (s[j] != ')') ++j;
                string key = s.substr(i+1,j-i-1);
                res += mp.count(key) ? mp[key] : "?";
                i = j + 1;
            } else {
                res += s[i++];
            }
        }
        return res;

    }
};