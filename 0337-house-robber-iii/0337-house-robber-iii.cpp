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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL) return {0,0};
        auto left=solve(root->left);
        auto right=solve(root->right);
        pair<int,int>p;
        p.first=root->val+left.second+right.second;
        p.second=max(left.first,left.second)+max(right.first,right.second);
        return p;
    }
    int rob(TreeNode* root){
        pair<int,int> p=solve(root);
        return max(p.first,p.second);
    }


    // int f(int i,vector<int>& levSum,vector<int>& dp){
    //     if(i==0) return levSum[0];
    //     if(i<0) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int notTake=0+f(i-1,levSum,dp);
    //     int Take=levSum[i]+f(i-2,levSum,dp);
    //     return dp[i]=max(Take,notTake);
    // }
    // int rob(TreeNode* root){
    //     if(root==NULL) return 0;
    //     vector<int> levSum;
    //     queue<TreeNode*> q;
    //     q.push(root);
    //     while(q.size()!=0){
    //         int size=q.size();
    //         int sum=0;
    //         while(size--){
    //             TreeNode* temp=q.front();
    //             q.pop();
    //             sum+=temp->val;
    //             if(temp->left) q.push(temp->left);
    //             if(temp->right) q.push(temp->right);
    //         }
    //         levSum.push_back(sum);
    //     }
    //     //NOW WE CAN APPLY HOUSE ROBBER ON LEVSUM VECTOR
    //     int n=levSum.size();
    //     vector<int> dp(n,-1);
    //     return f(n-1,levSum,dp);
    // }
};