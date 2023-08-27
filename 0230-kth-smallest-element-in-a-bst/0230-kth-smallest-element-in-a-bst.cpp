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
    void inorder(TreeNode* root,int& k,int& ans){
        if(root==NULL) return;
        inorder(root->left,k,ans);
        if(--k==0){
            ans=root->val;
            return;
        }
        inorder(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int k){
        if(root==NULL) return -1;
        int ans;
        inorder(root,k,ans);
        return ans;
    }
};


// node* kthsmallest(node* root,int &k){
// 	if(root==NULL) return NULL;
// 	node* left=kthsmallest(root->left,k);
// 	if(left!=NULL) return left;
// 	k--;
// 	if(k==0)
// 	return root;
// 	return kthsmallest(root->right,k);
// }