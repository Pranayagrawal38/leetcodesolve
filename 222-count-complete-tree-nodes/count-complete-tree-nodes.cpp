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
int lefth(TreeNode* node){
    if(node==NULL)
    return 0;
    int h=0;
    while(node){
         h++;
         //if(node->left)
         node=node->left;
    }
    return h;
}
int righth(TreeNode* node){
    if(node==NULL)
    return 0;
    int h=0;
    while(node){
         h++;
         //if(node->right)
         node=node->right;
    }
    return h;
}

    int countNodes(TreeNode* root) {
        if(root==NULL)
        return 0;
        int lh=lefth(root);
        int rh=righth(root);
        if(lh==rh)
        return (1<<lh)-1;
        else
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};