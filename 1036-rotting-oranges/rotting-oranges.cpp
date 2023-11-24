class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>visited(n,vector<int>(m,0));
        int fresh=0;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(grid[i][j]==1){
                fresh++;
                visited[i][j]=0;
               }

               else if(grid[i][j]==2){
                   q.push({{i,j},0});
                   visited[i][j]=2;
               }
               else
               visited[i][j]=0;

            }
        }
        int t=0;
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        while(!q.empty()){
            int a=q.front().first.first;
            int b=q.front().first.second;
            int tm=q.front().second;
            t=max(t,tm);
            q.pop();
            for(int i=0;i<4;i++){
                int ni=a+di[i];
                int nj=b+dj[i];
                if(ni>=0&&ni<n&&nj>=0&&nj<m&&visited[ni][nj]==0&&grid[ni][nj]==1){
                    q.push({{ni,nj},tm+1});
                    visited[ni][nj]=2;
                    c++;
                }
            }
        }
        if(c!=fresh)
        return -1;
        return t;
    }
};