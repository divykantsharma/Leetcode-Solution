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
    void inorder(TreeNode* root,vector<int>& in){
        if(!root) return;
        inorder(root->left,in);
        if(root->left==NULL && root->right==NULL){  //leaf node
            in.push_back(root->val);
        }
        inorder(root->right,in);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2) return true;
        vector<int> in1,in2;
        inorder(root1,in1);
        inorder(root2,in2);
        return in1==in2;
    }
};