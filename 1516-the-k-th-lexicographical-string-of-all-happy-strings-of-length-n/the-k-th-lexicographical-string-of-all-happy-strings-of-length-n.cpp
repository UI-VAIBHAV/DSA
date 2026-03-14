class Solution {
public:
    void count(int n,vector<string>&arr,string temp){
        if(temp.size()==n){
            arr.push_back(temp);
            return;
        }
        for(char ch='a';ch<='c';ch++) {
            if(temp.size() && temp.back()==ch) {
                continue;
            }
            count(n,arr,temp+ch);
        }
    }
    string getHappyString(int n, int k) {
        vector<string>arr;
        string temp="";
        count(n,arr,temp);
        sort(arr.begin(),arr.end());
        if(arr.size()>=k) return arr[k-1];
        return "";
    }
};