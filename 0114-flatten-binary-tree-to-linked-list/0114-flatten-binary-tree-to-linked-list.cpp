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
//As it is stated to create a LL with the TreeNode class , therefore we will use  the treenode class only
class Solution {
public:
    void preorder(TreeNode* root,vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    void flatten(TreeNode* root){
        if(root==NULL) return;
        vector<int> ans;
        preorder(root,ans);
        root->left=NULL;root->right=NULL;    //Breaking all the nodes connected to root node
        root->val=ans[0];
        TreeNode* temp=root;
        for(int i=1;i<ans.size();i++){
            TreeNode* newnode=new TreeNode(ans[i]);
            temp->right=newnode;
            temp=temp->right;
        }
    }
};