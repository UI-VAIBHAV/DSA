class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto &e:prerequisites){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }
        vector<int>indeg(numCourses,0);
        for(int i=0;i<adj.size();i++){
            for(int j=0;j<adj[i].size();j++) indeg[adj[i][j]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                indeg[adj[node][i]]--;
                if(indeg[adj[node][i]]==0) q.push(adj[node][i]);
            }
        }
        if(numCourses==ans.size()) return 1;
        return 0;
    }
};