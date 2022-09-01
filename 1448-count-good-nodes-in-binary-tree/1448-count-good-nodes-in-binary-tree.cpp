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
    int goodNodes(TreeNode* root){
        return solve(root,INT_MIN);
    }
int solve(TreeNode* root,int maxi){
     if(root==NULL) return 0;
    int count=0;
        if(root->val>=maxi){
            maxi=root->val;
            count++;
        }
        return count+solve(root->left,max(root->val,maxi))+solve(root->right,max(root->val,maxi));
}

};