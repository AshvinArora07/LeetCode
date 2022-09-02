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
    vector<double> averageOfLevels(TreeNode* root) {
                vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);                  // to mark end of a level 
        long long sum =0,count = 0;
        while(q.size()){
            TreeNode* cur = q.front();
            q.pop();
            if(!cur){
                ans.push_back((double)sum/count);     //  pushing in averages
                sum = 0,count = 0;
                q.push(NULL);
                if(!q.front())break;
            }
            else{
                count++;
                sum += cur->val;
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            }
        }
 
        return ans;

    }
};