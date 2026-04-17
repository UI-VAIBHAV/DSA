class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int cost=0;
        int V = points.size();
        vector<bool>mst(V,0);
        pq.push({0,0});
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(mst[node]) continue;
            cost += wt;
            mst[node] = 1;
            for(int i=0;i<V;i++){
                if(!mst[i]){
                    int dis = abs(points[node][0]-points[i][0])+abs(points[node][1]-points[i][1]);
                    pq.push({dis,i});
                }
            }
        }
        return cost;
    }
};