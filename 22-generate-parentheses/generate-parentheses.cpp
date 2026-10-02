class Solution {
public:
    void generate(int n,vector<string>&ans,string temp,int left,int right){
        if(left+right==2*n){
            ans.push_back(temp);
            return;
        }
        if(left<n){
            temp.push_back('(');
            generate(n,ans,temp,left+1,right);
            temp.pop_back();
        }
        if(right<left){
            temp.push_back(')');
            generate(n,ans,temp,left,right+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        generate(n,ans,temp,0,0);
        return ans;
    }
};