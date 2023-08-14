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
int maxLevelSum(TreeNode* root) {
        int result=INT_MIN;
        int maxi=0;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()) {
            int partialmaxi=0;
            ++level;
            for(int i=q.size();i>0;--i) {
                TreeNode* temp =q.front();
                q.pop();
                partialmaxi+=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(partialmaxi>result){
                result=partialmaxi;
                maxi=level;
            }
        }
        return maxi;
    }
};