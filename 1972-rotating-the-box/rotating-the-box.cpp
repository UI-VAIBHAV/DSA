class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        for(vector<char>&vec:boxGrid){
            int start=0,end=0;
            while(end<vec.size()){
                if(vec[start]!='#'){
                    start++;
                    end++;
                }
                else{
                    if(vec[end]=='*'){
                        end++;
                        start=end;
                    }
                    else if(vec[end]=='#') end++;
                    else{
                        swap(vec[start],vec[end]);
                        start++;
                        end++;
                    }
                }
            }
        }
        int m=boxGrid.size(),n=boxGrid[0].size();
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = boxGrid[m-1-j][i];
            }
        }
        return ans;
    }
};