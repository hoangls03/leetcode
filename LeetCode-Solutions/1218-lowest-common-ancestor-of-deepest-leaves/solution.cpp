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
    int depth( TreeNode* root) {
        if ( root == NULL ) {
            return 0;
        }
        return max(depth(root->right),depth(root->left)) + 1;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if ( root == NULL ) return NULL;

        int r = depth(root->right);
        int l = depth(root->left);

        if ( l == r ) {
            return root;
        }

        if ( l > r ) {
            return lcaDeepestLeaves(root->left);
        }

        return lcaDeepestLeaves(root->right);
    }
};
