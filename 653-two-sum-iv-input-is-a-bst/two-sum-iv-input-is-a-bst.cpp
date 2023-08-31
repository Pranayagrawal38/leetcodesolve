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
// TC => O(N)+O(N)
// SC => O(N)
void inordertrav(TreeNode* &root,vector<int>&inorder){
    if(root==NULL)
    return;
    inordertrav(root->left,inorder);
    inorder.push_back(root->val);
    inordertrav(root->right,inorder);
}
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inordertrav(root,inorder);
        int i=0,j=inorder.size()-1;
        int sum=0;
        bool p=false;
        while(i<j){
            sum=inorder[i]+inorder[j];
            if(sum==k){
                p=true;
                break;
            }
            else if(sum>k){
                j--;
            }
            else if(sum<k){
                i++;
            }

            
        }
        return p;
    }
};