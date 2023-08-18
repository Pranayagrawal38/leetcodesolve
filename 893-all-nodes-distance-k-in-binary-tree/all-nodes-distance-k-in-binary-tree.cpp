/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void markp(TreeNode* &root,unordered_map<TreeNode*,TreeNode*>&parent){
    queue<TreeNode*>pq;
    pq.push(root);
    while(!pq.empty()){
        TreeNode* node=pq.front();
        pq.pop();
        if(node->left){
            parent[node->left]=node;
            pq.push(node->left);
        }
        if(node->right){
            parent[node->right]=node;
            pq.push(node->right);
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        markp(root,parent);
        queue<TreeNode*>tq;
        tq.push(target);
        unordered_map<TreeNode*,bool>visited;
        visited[target]=true;
        int dist=0;
        while(!tq.empty()){
            int size=tq.size();
            if(dist==k)
            break;
            dist++;
            for(int i=0;i<size;i++){
                TreeNode* curr=tq.front();
                tq.pop();
                if(curr->left&&!visited[curr->left]){
                    tq.push(curr->left);
                    visited[curr->left]=true;
                }
                if(curr->right&&!visited[curr->right]){
                    tq.push(curr->right);
                    visited[curr->right]=true;
                }
                if(parent[curr]&&!visited[parent[curr]]){
                    tq.push(parent[curr]);
                    visited[parent[curr]]=true;
                }
            }
        }
        vector<int>ans;
        while(!tq.empty()){
            TreeNode* c=tq.front();
            tq.pop();
            ans.push_back(c->val);
        }
        return ans;
    }
};