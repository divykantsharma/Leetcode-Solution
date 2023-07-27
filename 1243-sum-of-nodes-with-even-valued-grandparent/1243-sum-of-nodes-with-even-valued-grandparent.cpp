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
    int sum=0;
    void f(TreeNode* root){
        if(root==NULL) return;
        if(root->left) sum+=root->left->val;
        if(root->right) sum+=root->right->val;
    }
    int sumEvenGrandparent(TreeNode* root){
        if(root==NULL) return 0;
        if(root->val%2==0){
            f(root->left);
            f(root->right);
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return sum;
    }
};