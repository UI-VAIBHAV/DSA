class Solution {
public:
    int row[4] = {-1,0,1,0};
    int col[4] = {0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) { 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        int m = heights.size(),n=heights[0].size();
        vector<vector<int>>arr(m,vector<int>(n,INT_MAX));
        arr[0][0]=0;
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int diff = p.first;
            int i = p.second.first;
            int j = p.second.second;
            if(i==m-1 && j==n-1) return diff;
            for(int k=0;k<4;k++){
                int new_i = i+row[k];
                int new_j = j+col[k];
                if(new_i>=0 && new_j>=0 && new_i<m && new_j<n ){
                    int new_effort = max(abs(heights[i][j]-heights[new_i][new_j]),diff);
                    if(new_effort < arr[new_i][new_j]){
                        arr[new_i][new_j] = new_effort;
                        pq.push({arr[new_i][new_j],{new_i,new_j}});
                    }
                }
            }
           
        }
        return arr[m-1][n-1];
    }
};