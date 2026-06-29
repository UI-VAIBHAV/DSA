class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        unordered_map<string,bool>mp;
        for(int i=0;i<word.size();i++){
            string s="";
            for(int j=i;j<word.size();j++){
                s += word[j];
                mp[s] = 1;
            }
        }
        int ans=0;
        for(string s:patterns){
            if(mp[s]) ans++;
        }
        return ans;
    }
};