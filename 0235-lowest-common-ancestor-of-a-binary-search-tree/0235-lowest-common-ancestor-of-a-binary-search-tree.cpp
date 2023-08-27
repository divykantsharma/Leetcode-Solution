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
    //BST
    TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root==NULL) return NULL;
        if(p->val<root->val && q->val<root->val) return lowestCommonAncestor(root->left,p,q);
        if(p->val>root->val && q->val>root->val) return lowestCommonAncestor(root->right,p,q);
        else return root;
    }


    //BINARY TREE
    // TreeNode* lowestCommonAncestor(TreeNode* root,TreeNode* p,TreeNode* q){
    //     if(root==NULL) return NULL;
    //     if(root->val==p->val || root->val==q->val) return root;
    //     TreeNode* left=lowestCommonAncestor(root->left,p,q);
    //     TreeNode* right=lowestCommonAncestor(root->right,p,q);
    //     if(left==NULL) return right;
    //     else if(right==NULL) return left;
    //     else return root;
    // }
};