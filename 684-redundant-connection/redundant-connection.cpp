class Solution {
public:
    bool cycle(vector<vector<int>>&adj,vector<bool>&visited,int node,int par){
        visited[node]=1;
        for(auto neighbour:adj[node]){
            if(!visited[neighbour]){
                if(cycle(adj,visited,neighbour,node)){
                    return 1;
                }
            }
            else if(neighbour!=par){
                return 1;
            }
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>>adj(edges.size());
        for(auto &e:edges){
            int u = e[0]-1;
            int v = e[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool>visited(adj.size(),0);
            if(cycle(adj,visited,u,-1)) return e;
        }
        return {-1,-1};
    }
};