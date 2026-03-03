class Solution {
public:
    char findKthBit(int n, int k) {
        string fin="0";
        for(int i=2;i<=n;i++){
            string temp = fin;
            fin += "1";
            reverse(temp.begin(),temp.end());
            transform(temp.begin(), temp.end(), temp.begin(), [](char c) {
                return (c == '0') ? '1' : '0';
            });
            fin += temp;
        }
        return fin[k-1];
    }
};