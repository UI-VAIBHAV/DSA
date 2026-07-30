class Solution {
public:
    int minimumPushes(string word) {
        vector<int>box(26,0);
        for(auto &c:word){
            box[c-'a']++;
        }
        int result = 0;
        sort(box.begin(),box.end(),greater<int>());
        for(int i=0;i<26;i++){
            int freq = box[i];
            int press = i/8 + 1;
            result += freq*press;
        }
        return result;
    }
};