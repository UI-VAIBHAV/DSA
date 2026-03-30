class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n);
        for(auto &e:relations){
            int u = e[0]-1;
            int v = e[1]-1;
            adj[u].push_back(v);
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<adj[i].size();j++) indeg[adj[i][j]]++;
        } 
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        int ans=0;
        vector<int>course(n,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0) q.push(adj[node][i]);
                course[adj[node][i]] = max(course[adj[node][i]],course[node]+time[node]);
            }
        }
        for(int i=0;i<n;i++) ans = max(ans,course[i]+time[i]);
        return ans;
    }
};