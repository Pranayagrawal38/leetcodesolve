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

int maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

bool isBalanced(TreeNode* root) {
    if (root == nullptr)
        return true;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    if (abs(leftDepth - rightDepth) > 1)
        return false;

    bool leftBalanced = isBalanced(root->left);
    bool rightBalanced = isBalanced(root->right);

    return leftBalanced && rightBalanced;
}
    
};