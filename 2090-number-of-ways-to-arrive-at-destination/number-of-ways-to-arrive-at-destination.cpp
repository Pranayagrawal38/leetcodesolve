class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long>d(n,1e18);
        vector<long long>w(n,0);
        d[0]=0;
        w[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        int mod=1e9+7;
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int weight=it.second;
                if(weight+dist<d[adjnode]){
                    d[adjnode]=weight+dist;
                    pq.push({d[adjnode],adjnode});
                    w[adjnode]=w[node];
                }
                else if(weight+dist==d[adjnode]){
                    w[adjnode]=(w[adjnode]+w[node])%mod;
                }
            }

        }
        return w[n-1]%mod;
    }
};
