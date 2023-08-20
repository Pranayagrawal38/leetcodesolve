/**
 * Definition for a binary tree root.
 * struct Treeroot {
 *     int val;
 *     Treeroot *left;
 *     Treeroot *right;
 *     Treeroot() : val(0), left(nullptr), right(nullptr) {}
 *     Treeroot(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Treeroot(int x, Treeroot *left, Treeroot *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
        //Recursive
TreeNode* prev=NULL;
    void flatten(TreeNode* root) {

        
        if(root==NULL)
        return;
        flatten(root->right);
        flatten(root->left);
        root->right=prev;
        root->left=NULL;
        prev=root;
    }
};