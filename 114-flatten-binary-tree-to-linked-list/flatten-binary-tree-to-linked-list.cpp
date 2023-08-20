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
    //Morris Method
    //TC => O(N)
    //SC => O(1)
    void flatten(TreeNode* root) {
        if(root==NULL)
        return;
        TreeNode* curr=root;
        TreeNode* prev;
        while(curr!=NULL){
            if(curr->left!=NULL){
               prev=curr->left;
               while(prev->right!=NULL){
                   prev=prev->right;
               }
               prev->right=curr->right;
               curr->right=curr->left;
               curr->left=NULL;
            }
            curr=curr->right;
        }
        
    }
};