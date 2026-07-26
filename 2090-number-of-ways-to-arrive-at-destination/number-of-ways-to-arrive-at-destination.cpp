class Solution {
public:
    int mod = 1000000007; 
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &e:roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        vector<long long>wei(n, LLONG_MAX);
        vector<int>ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        pq.push({0,0});
        wei[0]=0;
        ways[0]=1;
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int nei = it.first;
                int ndis = it.second;
                if(dis+ndis<wei[nei]){
                    wei[nei] = dis+ndis;
                    pq.push({dis+ndis,nei});
                    ways[nei] = ways[node];
                }
                else{
                    if(dis+ndis==wei[nei]){
                        ways[nei] = (ways[node]+ways[nei])%mod;
                    }
                }
            }
        }
        return ways[n-1]%mod;
    }
};