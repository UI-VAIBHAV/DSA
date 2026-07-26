class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:flights){
            adj[e[0]].push_back({e[1],e[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dis(n,INT_MAX);
        dis[src] = 0;
        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int wei = q.front().second.second;
            q.pop();
            if(stop>k) continue;
            for(int i=0;i<adj[node].size();i++){
                int adjnode = adj[node][i].first;
                int nwei = adj[node][i].second;
                if(nwei + wei<dis[adjnode] && stop<=k){
                    dis[adjnode] = wei+nwei;
                    q.push({stop+1,{adjnode,nwei+wei}});
                }
            }

        }
        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];
    }
};