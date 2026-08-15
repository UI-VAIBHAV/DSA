class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int st1=0,st2=0,count=0;
        while(st1<g.size() && st2<s.size()){
            if(g[st1]<=s[st2]){
                count++;
                st1++;
                st2++;
            }
            else{
                st2++;
            }
        }
        return count;
    }
};