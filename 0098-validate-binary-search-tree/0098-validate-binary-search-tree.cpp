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
    //SOLUTION 2
    bool isBST_helper(TreeNode* root,long long mini=LONG_MIN,long long maxi=LONG_MAX){
        if(root==NULL) return true;
        if(mini>=root->val || root->val>=maxi) return false;
        return isBST_helper(root->left,mini,root->val) && 
                    isBST_helper(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root){
        if(root==NULL) return true;
        return isBST_helper(root);
    }


    //SOLUTION 1
    // long long int min(long long int x,long long int y){
    //     return (x>y)?y:x;
    // }
    // long long int max(long long int x,long long int y){
    //     return (x>y)?x:y;
    // }
    // long long int maximum(TreeNode* root){
    //     if(root==NULL) return LLONG_MIN;
    //     return max(root->val,max(maximum(root->left),maximum(root->right)));
    // }
    // long long int minimum(TreeNode* root){ 
    //     if(root==NULL) return LLONG_MAX;
    //     return min(root->val,min(minimum(root->left),minimum(root->right)));
    // }
    // bool isValidBST(TreeNode* root){
    //     if(root==NULL) return true;
    //     return (isValidBST(root->left)) && (isValidBST(root->right)) && 
    //                 (root->val>maximum(root->left)) && (root->val<minimum(root->right));
    // }
};