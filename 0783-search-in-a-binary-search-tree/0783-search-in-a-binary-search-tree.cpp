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
    //RECURSIVE
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL) return root;
        TreeNode *node=root;
        if(root->val>val) node=searchBST(root->left,val);
        else if(root->val<val) node=searchBST(root->right,val);
        else node=root;
        return node;
    }


    //ITERATIVE;
    // TreeNode* searchBST(TreeNode* root, int val) {
    //     if(root==NULL) return NULL;
    //     while(root!=NULL){
    //         if(root->val==val) return root;
    //         if(root->val>val) root=root->left;
    //         else if(root->val<val) root=root->right;
    //     }
    //     return NULL;
    // }
};