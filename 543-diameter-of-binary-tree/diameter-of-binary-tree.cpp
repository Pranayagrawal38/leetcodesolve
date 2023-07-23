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
int md(TreeNode* root){
    if(root==NULL)
    return 0;
    int l=md(root->left);
    int r=md(root->right);
    return max(l,r)+1;
}

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        return 0;
        int left=md(root->left);
        int right=md(root->right);
        //int maxi=0;
        int diameter = left + right;
        int maxi = diameter; // Update maxi with the current diameter
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        maxi = max(maxi, max(leftDiameter, rightDiameter)); 

        return maxi;
    }
};