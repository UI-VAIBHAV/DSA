class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e:times){
            int u = e[0];
            int v = e[1];
            int weight = e[2];
            adj[u].push_back({v,weight});
        }
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        vector<bool>explored(n+1,0);
        p.push({0,k});
        dis[k] = 0;
        while(!p.empty()){
            int node = p.top().second;
            p.pop();
            if(explored[node]) continue;
            explored[node] = 1;
            for(int i=0;i<adj[node].size();i++){
                int neigh = adj[node][i].first;
                int weight = adj[node][i].second;
                if(!explored[neigh] && dis[neigh]>dis[node]+weight){
                    dis[neigh] = dis[node]+weight;
                    p.push({dis[neigh],neigh});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            ans = max(ans,dis[i]);
        }
        return ans;
    }
};