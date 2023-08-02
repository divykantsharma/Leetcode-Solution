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
//SAME QUES: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/description/
    TreeNode* LCA(TreeNode* root,TreeNode* root1,TreeNode* root2){
        if(!root) return root;
        if(root==root1||root==root2) return root;
        TreeNode* left=LCA(root->left,root1,root2);
        TreeNode* right=LCA(root->right,root1,root2);
        if(!left) return right;
        else if(!right) return left;
        else return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root){
        if(!root) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> vec;
        while(q.size()!=0){
            int size=q.size();
            while(size--){
                TreeNode* top=q.front();
                q.pop();
                vec.push_back(top);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
            }
            if(!q.empty()) vec.clear();
        }
        if(vec.size()==1) return vec[0];
        TreeNode* root1=vec[0];
        TreeNode* root2=vec[vec.size()-1];
        return LCA(root,root1,root2);
    }
};