class Solution {
public:
void dfs(vector<vector<int>>& isConnected,int n,int sv,bool *visited){
    visited[sv]=true;
    for(int i=0;i<n;i++){
        if(i==sv)
        continue;
        if(isConnected[sv][i]==1&&!visited[i]){
            dfs(isConnected,n,i,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        bool visited[n];
        for(int i=0;i<n;i++){
            visited[i]=false;
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                c++;
                dfs(isConnected,n,i,visited);

            }
        }
        return c;
    }
};