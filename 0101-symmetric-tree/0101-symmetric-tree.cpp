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
  //recursive  
    /*bool helper(TreeNode* leftNode,TreeNode* rightNode){
        if(leftNode==NULL && rightNode==NULL)
            return true;
        if(leftNode==NULL||rightNode==NULL||leftNode->val!=rightNode->val)
            return false;
        return helper(leftNode->left,rightNode->right) && helper(rightNode->left,leftNode->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return helper(root->left,root->right);
    }*/
    
 //iterative(Using Queue)
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty()){
            TreeNode* leftNode=root->left;
            TreeNode*rightNode=root->right;
            leftNode=q.front();
            q.pop();
            rightNode=q.front();
            q.pop();
            if(leftNode==NULL && rightNode==NULL) continue;
            if(leftNode==NULL||rightNode==NULL||leftNode->val!=rightNode->val) return false;
            
            //Now pushing the childs of the left and right node if the values of these nodes are equal
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(rightNode->left);
            q.push(leftNode->right);
            
        }
        return true;
    }
};