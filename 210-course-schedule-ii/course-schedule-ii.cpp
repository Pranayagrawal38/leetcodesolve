class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        // In-degree array initialization
        vector<int> ind(numCourses, 0);
        
        // Calculate in-degrees
        for(int i = 0; i < numCourses; i++){
            for(auto it : adj[i]){
                ind[it]++;
            }
        }
        
        queue<int> q;
        
        // Add courses with no prerequisites
        for(int i = 0; i < numCourses; i++){
            if(ind[i] == 0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            // Decrease in-degree of neighbors
            for(auto it : adj[node]){
                ind[it]--;
                if(ind[it] == 0){
                    q.push(it);
                }
            }
        }
        
        // Check if all courses are processed
        if(ans.size() != numCourses) {
            return {}; // Return empty as we have a cycle or couldn't process all courses
        }

       return ans;
    }
};
