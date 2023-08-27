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
    //MORRIS TRAVERSAL - USING INORDER
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> inorder;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){   //this curr itself is the bottom most root, therefore print it
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr){
                    prev=prev->right;                    
                }
                if(prev->right==NULL){
                    prev->right=curr;   //making of a thread
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    inorder.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return inorder;
    }


    //ITERATIVE
    // vector<int> inorderTraversal(TreeNode* root){
    //     vector<int> ans;
    //     stack<TreeNode*> st;
    //     TreeNode* node=root;
    //     while(true){
    //         if(node!=NULL){
    //             st.push(node);
    //             node=node->left;
    //         }
    //         else{
    //             if(st.empty()) break;
    //             node=st.top();
    //             st.pop();
    //             ans.push_back(node->val);
    //             node=node->right;
    //         }
    //     }
    //     return ans;
    // }


    //RECURSIVE WITH HELPER FUNCTION - BETTER TC AND SC
    // void inorder(TreeNode* root,vector<int>& ans){
    //     if(root==NULL) return;
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    // }
    // vector<int> inorderTraversal(TreeNode* root){
    //     vector<int> ans;
    //     if(root==NULL) return ans;
    //     inorder(root->left,ans);
    //     ans.push_back(root->val);
    //     inorder(root->right,ans);
    //     return ans;
    // }


//RECURSIVE WITHOUT HELPER FUNCTION
//LESS OPTIMIZED as compared to above one - as iss wale mei recursion call stack is large therefore humare vector ko zyada derr baith kar wait karna padega
    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> ans,left,right;
    //     if(root==NULL) return ans;
    //     left=inorderTraversal(root->left);
    //     for(int i=0;i<left.size();i++){
    //         ans.push_back(left[i]);
    //     }
    //     ans.push_back(root->val);
    //     right=inorderTraversal(root->right);
    //     for(int i=0;i<right.size();i++){
    //         ans.push_back(right[i]);
    //     }
    //     return ans;
    // }
};