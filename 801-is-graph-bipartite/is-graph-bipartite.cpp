class Solution {
public:
bool dfs(int node,int sv,int mark[],vector<vector<int>>& graph){
 if(mark[node]!=-1)
 return (mark[node]==sv);
 mark[node]=sv;
 for(int it:graph[node]){
     if(!dfs(it,!sv,mark,graph))
     return false;
 }
 return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int mark[n];
        for(int i=0;i<n;i++){
            mark[i]=-1;
        }
        for(int i=0;i<n;i++){
            if(mark[i]==-1){
                if(dfs(i,0,mark,graph)==false)
                return false;
            }
        }
        return true;
    }

};