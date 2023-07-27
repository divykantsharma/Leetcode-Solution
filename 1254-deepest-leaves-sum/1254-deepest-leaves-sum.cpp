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
    int deepestLeavesSum(TreeNode* root){
        if(root==NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int finalSum=0;
        while(q.size()!=0){
            int size=q.size();
            int tempSum=0;
            while(size--){
                TreeNode* curr=q.front();
                q.pop();
                tempSum+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            finalSum=tempSum;
        }
        return finalSum;
    }
};