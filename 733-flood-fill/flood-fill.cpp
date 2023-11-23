class Solution {
public:
void bfs(vector<vector<int>>& image,vector<vector<int>>&ans,int color,int di[],int dj[],int inicolor,int sr,int sc){
    queue<pair<int,int>>q;
    q.push({sr,sc});
    ans[sr][sc]=color;
    int n=image.size();
    int m=image[0].size();
    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ni=a+di[i];
            int nj=b+dj[i];
            if(ni>=0&&ni<n&&nj>=0&&nj<m&&image[ni][nj]==inicolor&&ans[ni][nj]!=color){
                ans[ni][nj]=color;
                q.push({ni,nj});
            }
        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int inicolor=image[sr][sc];
       vector<vector<int>>ans= image;
       int di[]={-1,0,+1,0};
       int dj[]={0,+1,0,-1};
       bfs(image,ans,color,di,dj,inicolor,sr,sc);
       return ans;
    
    }
};