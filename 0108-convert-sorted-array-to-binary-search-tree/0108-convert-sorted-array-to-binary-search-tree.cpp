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
    TreeNode* helper(vector<int>& nums,int si,int ei){
        if(nums.size()==0) return NULL;
        if(si>ei) return NULL;
        int rootindex=(si+ei)/2;
        TreeNode* root=new TreeNode(nums[rootindex]);
        root->left=helper(nums,si,rootindex-1);
        root->right=helper(nums,rootindex+1,ei);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums){
        if(nums.size()==0) return NULL;
        return helper(nums,0,nums.size()-1); 
    }
};