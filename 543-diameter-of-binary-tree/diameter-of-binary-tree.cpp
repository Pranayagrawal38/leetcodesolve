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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root==NULL)
        return 0;
        int dia=0;
        d(root,dia);
        return dia;
    }
    int d(TreeNode* root,int &dia){
        if(root==NULL)
        return 0;
        int maxi=0;
        int lh=d(root->left,dia);
        int rh=d(root->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
    }
};