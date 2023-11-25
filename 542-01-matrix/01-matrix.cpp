class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
                else{
                    visited[i][j]=0;
                }
            }
        }
        int di[]={-1,0,1,0};
        int dj[]={0,1,0,-1};
        while(!q.empty()){
            int a=q.front().first.first;
            int b=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            distance[a][b]=dist;
            for(int i=0;i<4;i++){
                int ni=a+di[i];
                int nj=b+dj[i];
                while(ni>=0&&ni<n&&nj>=0&&nj<m&&!visited[ni][nj]){//&&mat[ni][nj]==0){
                    visited[ni][nj]=1;
                    q.push({{ni,nj},dist+1});
                }
            }
        }
        return distance;

    }
};