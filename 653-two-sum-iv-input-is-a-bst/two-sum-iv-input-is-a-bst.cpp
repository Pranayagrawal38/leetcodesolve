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
 class BSTiterator{
    stack<TreeNode*>st;
    // reverse->true then before
    // reverse->false then next
    bool reverse=true;
    public:
    BSTiterator(TreeNode*root,bool isReverse){
        reverse=isReverse;
        pushall(root);
    }
    bool hasnext(){
        return !st.empty();
    }
    int next(){
        TreeNode* t=st.top();
        st.pop();
        if(!reverse)
        pushall(t->right);
        else
        pushall(t->left);
        return t->val;
    }
    void pushall(TreeNode* node){
        while(node!=NULL){
            st.push(node);
            if(reverse==true){
                node=node->right;
            }
            else{
                node=node->left;
            }
        }
    }
 };
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL)
        return false;
        BSTiterator l(root,false);
        BSTiterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if((i+j)==k)
            return true;
            else if((i+j)>k)
            j=r.next();
            else
            i=l.next();
        }
        return false;
    }
};