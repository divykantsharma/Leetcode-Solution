//Pepcoding - https://www.youtube.com/watch?v=qOItdXuTZGo
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
    vector<TreeNode*> helper(int st,int en){
        vector<TreeNode*> ans;
        if(st>en){
            ans.push_back(NULL);
            return ans;
        }
        for(int i=st;i<=en;i++){
            vector<TreeNode*> left=helper(st,i-1);
            vector<TreeNode*> right=helper(i+1,en);
            for(auto l:left){
                for(auto r:right){
                    TreeNode* root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n){
        // if(n==0) return vector<TreeNode*>(0);
        return helper(1,n);
    }
};