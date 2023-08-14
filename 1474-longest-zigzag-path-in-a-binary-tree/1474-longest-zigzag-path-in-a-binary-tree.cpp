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
class Solution{
public:
    int maxi=INT_MIN;
    int rightToLeft(TreeNode* root){
        int count=0;
        while(root!=NULL){
            if(count%2==0) root=root->right;
            else root=root->left;
            count++;
        }
        return count;
    }
    int leftToRight(TreeNode* root){
        int count=0;
        while(root!=NULL){
            if(count%2==0) root=root->left;
            else root=root->right;
            count++;
        }
        return count;
    }
    int longestZigZag(TreeNode* root){
        if(root==NULL) return 0;
        maxi=max(maxi,max(rightToLeft(root),leftToRight(root)));
        maxi=max(maxi,max(longestZigZag(root->left),longestZigZag(root->right)));
        return maxi-1;
    }
};