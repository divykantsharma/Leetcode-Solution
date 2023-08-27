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
    int height(TreeNode* node,int& dia){     //STRIVER
        if(node==NULL) return 0;
        int lh=height(node->left,dia);
        int rh=height(node->right,dia);
        dia=max(dia,lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=INT_MIN;
        cout<<height(root,diameter)<<" ";
        return diameter;
    }


    // TC would be high as we are calculating height again for diameter - therefore reducing it by making a pair class of height and diameter
    // int height(TreeNode* root){
    //     if(root==NULL) return 0;
    //     return 1+max(height(root->right),height(root->left));
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root==NULL) return 0;
    //     int option1=height(root->left)+height(root->right);
    //     int option2=diameterOfBinaryTree(root->left);
    //     int option3=diameterOfBinaryTree(root->right);
    //     return max(option1,max(option2,option3));
    // }


    // MAKING A PAIR CLASS
    // pair<int,int> heightdiameter(TreeNode* root){
    //     if(root==NULL){
    //         pair<int,int> p;
    //         p.first=0;          //height of binary tree
    //         p.second=0;         //diameterof binary tree
    //         return p;
    //     }
    //     pair<int,int> leftans=heightdiameter(root->left);
    //     pair<int,int> rightans=heightdiameter(root->right);
    //     int left_dia=leftans.second;
    //     int right_dia=rightans.second;
    //     int left_height=leftans.first;
    //     int right_height=rightans.first;
    
    //     int height=1+max(left_height,right_height);
    //     int diameter=max(left_height+right_height,max(left_dia,right_dia));
    //     pair<int,int> p;
    //     p.first=height;
    //     p.second=diameter;
    //     return p;
    // }
    // int diameterOfBinaryTree(TreeNode* root){
    //     pair<int,int> ans=heightdiameter(root);
    //     return ans.second;
    // }
};