class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> ind(n, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            for (int j : graph[i]) {
                adj[j].push_back(i);
            }
         ind[i] = graph[i].size();
            if (ind[i] == 0) {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int neighbor : adj[node]) {
                ind[neighbor]--;
                if (ind[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        sort(ans.begin(), ans.end());
       return ans;
    }
};