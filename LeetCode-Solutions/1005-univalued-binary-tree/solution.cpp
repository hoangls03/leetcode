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
    void travel(TreeNode* root, bool& ans ) {
        if ( root == NULL ) return;
        if ( root -> left != NULL ) {
            if ( root->val != root->left->val ) ans = false;
        }
        if ( root -> right != NULL ) {
            if ( root->val != root->right->val ) ans = false;
        }
        travel(root->left,ans);
        travel(root->right,ans);
    }
    bool isUnivalTree(TreeNode* root) {
        bool ans = true;
        travel(root,ans);
        return ans;
    }
};
