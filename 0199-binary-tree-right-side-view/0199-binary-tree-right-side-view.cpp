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
    // RECURSIVE WAY - REVERSE PREORDER TRAVERSAL
    void recursion(TreeNode *root,int level,vector<int> &res){
        if(root==NULL) return ;    //as soon as a level is increased push in vector takes place 
        if(res.size()==level) res.push_back(root->val);
        recursion(root->right,level+1,res);
        recursion(root->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode *root){
        vector<int> res;
        recursion(root,0,res);
        return res;
    }


    // ITERATIVE WAY - LEVEL ORDER TRAVERSAL
    // vector<int> rightSideView(TreeNode* root) {
    //     vector<int> ans;
    //     if(root == NULL) return ans;
    //     queue<TreeNode*>q;
    //     q.push(root);
    //     while(q.size()!=0){
    //         int size=q.size();
    //         int data=0;
    //         while(size>0){
    //             TreeNode* temp=q.front();
    //             q.pop();
    //             data=temp->val;
    //             if(temp->left!=NULL) q.push(temp->left);
    //             if(temp->right!=NULL) q.push(temp->right);
    //             size--;
    //         }
    //         ans.push_back(data);
    //     }
    //     return ans;
    // }
};