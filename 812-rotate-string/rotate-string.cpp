class Solution {
public:
    string rotate(string &s){
        char c = s[0];
        for(int i=1;i<s.size();i++){
            s[i-1] = s[i];
        }
        s[s.size()-1] = c;
        return s;
    }
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            if(s==goal) return 1;
            rotate(s);
        }
        return 0;
    }
};