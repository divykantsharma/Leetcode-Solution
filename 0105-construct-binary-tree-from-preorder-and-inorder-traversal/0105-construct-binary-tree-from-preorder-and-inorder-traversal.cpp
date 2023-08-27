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
    //STRIVER
    TreeNode* buildTree_helper(vector<int>& preorder,vector<int>& inorder,int preStart,
                                int preEnd,int inStart,int inEnd,map<int,int>& mp){
        if(preStart>preEnd || inStart>inEnd) return NULL;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot=mp[preorder[preStart]]; 
        int numsLeft=inRoot-inStart;
        root->left=buildTree_helper(preorder,inorder,preStart+1,preStart+numsLeft,inStart,inRoot-1,mp);
        root->right=buildTree_helper(preorder,inorder,preStart+numsLeft+1,preEnd,inRoot+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        map<int,int> mp;    //map of inorder values
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return buildTree_helper(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,mp);
    }


    //CODING NINJAS
    // TreeNode* buildTree_helper(vector<int>& preorder,vector<int>& inorder,int inorder_start,int inorder_end,int preorder_start,int preorder_end){
    //     if(inorder_start>inorder_end) return NULL;
    //     int rootData=preorder[preorder_start];
    //     int rootIndex;
    //     for(int i=0;i<inorder.size()-1;i++){
    //         if(inorder[i]==rootData){
    //             rootIndex=i;
    //             break;
    //         }
    //     }

    //     int left_inorder_start = inorder_start;
    //     int left_inorder_end = rootIndex-1;
    //     int left_preorder_start = preorder_start+1;
    //     int left_preorder_end = left_inorder_end - left_inorder_start + left_preorder_start;
    //     int right_inorder_start = rootIndex+1;
    //     int right_inorder_end = inorder_end;
    //     int right_preorder_start = left_preorder_end + 1;
    //     int right_preorder_end = preorder_end;

    //     TreeNode* root=new TreeNode(rootData);
    //     root->left=buildTree_helper(preorder,inorder,left_inorder_start,left_inorder_end,left_preorder_start,left_preorder_end);
    //     root->right=buildTree_helper(preorder,inorder,right_inorder_start,right_inorder_end,right_preorder_start,right_preorder_end);
    //     return root;
    // }
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
    //     return buildTree_helper(preorder,inorder,0,inorder.size()-1,0,preorder.size()-1);
    // }
};