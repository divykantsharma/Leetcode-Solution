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
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root==NULL) return NULL;
        if(key<root->val){
            root->left=deleteNode(root->left,key);
            return root;
        } 
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
            return root;
        }
        else{       //root node is deleted
            if(root->left==NULL && root->right==NULL){      //leaf node
                delete root;
                return NULL;
            }
            else if(root->left==NULL && root->right!=NULL){    //only the right child exist
                TreeNode* temp=root->right;
                root->right=NULL;
                delete root;
                return temp;
            }
            else if(root->left!=NULL && root->right==NULL){    //only the left child exist
                TreeNode* temp=root->left;
                root->left=NULL;
                delete root;
                return temp;
            }
            else{                 //both left and right subtree exists
               TreeNode* minnode=root->right; 
                while(minnode->left!=NULL){     //either take the smallest guy from right subtree
                   minnode=minnode->left;       //or the largest guy from the left subtree
                }
                int rightmin=minnode->val;
                root->val=rightmin;
                root->right=deleteNode(root->right,rightmin);
                return root;
            }
        }
        return root;
    }
};