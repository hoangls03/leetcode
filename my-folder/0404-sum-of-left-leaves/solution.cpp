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
    void travel( TreeNode* root, int &ans, int status ) {
        if ( root == NULL ) return;
        if ( root -> left == NULL && root -> right == NULL && status == 0 ) ans += root -> val;
        travel(root->left,ans,0);
        travel(root->right,ans,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        travel(root,ans,1);
        return ans;
    }
};
