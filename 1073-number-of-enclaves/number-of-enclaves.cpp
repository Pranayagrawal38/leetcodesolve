class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
            }
        }
            int di[]={-1,0,1,0};
            int dj[]={0,1,0,-1};
            while(!q.empty()){
                int a=q.front().first;
                int b=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int ni=a+di[i];
                    int nj=b+dj[i];
                    if(ni>=0&&ni<n&&nj>=0&&nj<m&&grid[ni][nj]==1&&visited[ni][nj]==0){
                        q.push({ni,nj});
                        visited[ni][nj]=1;
                    }
                }
            }
            int c=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==1&&visited[i][j]==0)
                    c++;
                }
            }

        return c;
    }
};