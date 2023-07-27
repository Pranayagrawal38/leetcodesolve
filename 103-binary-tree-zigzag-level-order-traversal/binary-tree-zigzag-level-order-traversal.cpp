/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>queuenode;
        vector<vector<int>>ans;
        if(root==NULL)
        return ans;
        queuenode.push(root);
        int flag=0;
        while(!queuenode.empty()){
            int size=queuenode.size();
            vector<int>v(size);
            for(int i=0;i<size;i++){
                TreeNode* node=queuenode.front();
                queuenode.pop();
                int index;
                if(flag==0)
                index=i;
                else
                index=size-1-i;
                v[index]=node->val;

                if(node->left)
                queuenode.push(node->left);
                if(node->right)
                queuenode.push(node->right);
            }
            if(flag==1)
            flag=0;
            else
            flag=1;
            ans.push_back(v);
        }
        return ans;
    }
};