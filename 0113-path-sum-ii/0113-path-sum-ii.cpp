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
    bool isLeaf(TreeNode* root){
        if(root==NULL) return false;
        return root->left==NULL && root->right==NULL;
    }
    void getPath(TreeNode* root,int targetSum,vector<int>& temp,vector<vector<int>>& ans){
        if(root==NULL) return;
        if(isLeaf(root)&&targetSum==root->val){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        targetSum-=root->val;
        temp.push_back(root->val);
        getPath(root->left,targetSum,temp,ans); 
        getPath(root->right,targetSum,temp,ans);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum){
        vector<vector<int>> ans;
        vector<int> temp;
        if(root==NULL) return ans;
        getPath(root,targetSum,temp,ans); 
        return ans;
    }
};