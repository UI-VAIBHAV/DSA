class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int j=0;j<graph.size();j++){
            if(color[j]==-1){
            queue<int>q;
            q.push(j);
            color[j] = 0;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(int i=0;i<graph[node].size();i++){
                    if(color[graph[node][i]]==-1){
                        color[graph[node][i]] = (color[node]+1)%2;
                        q.push(graph[node][i]);
                    }
                    else{
                        if(color[graph[node][i]]==color[node]) return false;
                    }
                }
            }
        }
        }
        return true;
    }
};