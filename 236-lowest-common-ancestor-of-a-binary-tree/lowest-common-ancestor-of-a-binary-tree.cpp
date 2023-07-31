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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q)
        return root;
        TreeNode* left=lowestCommonAncestor(root->left,p,q);//check left
        TreeNode* right=lowestCommonAncestor(root->right,p,q);//check right
        if(left==NULL)//if left is null
        return right;
        else if(right==NULL)// if right is null
        return left;
        else //if both is null then return the root
        return root;

    }
};