class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0];
        pq.push({0,{0,0}});
        vector<vector<int>> dir={{-1,0},{0,1},{1,0},{0,-1}};
        while(!pq.empty()){
            int dis=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1&&c==m-1)
            return dis;
            for(auto dr:dir){
                int newr=r+dr[0];
                int newc=c+dr[1];
                if(newr>=0&&newr<n&&newc>=0&&newc<m){
                    int effort=max(abs(heights[r][c]-heights[newr][newc]),dis);
                    if(effort<dist[newr][newc]){
                        dist[newr][newc]=effort;
                        pq.push({effort,{newr,newc}});
                    }
                }

            }

            
        }
        return -1;
        
    }
};