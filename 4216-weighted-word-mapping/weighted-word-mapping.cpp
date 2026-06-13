class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int,char>mp;
        int i=0;
        vector<int>arr;
        for(string s:words){
            int temp=0;
            for(char c:s){
                temp += weights[c-'a'];
                i++;
            }
            arr.push_back(temp%26);
        }
        for(int i=0;i<26;i++){
            char c = 'z'-i;
            mp[i] = c;
            c--;
        }
        string ans;
        for(int i:arr) ans += mp[i];
        return ans;
    }
};