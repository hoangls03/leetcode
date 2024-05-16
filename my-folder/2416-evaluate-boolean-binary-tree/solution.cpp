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
    bool travel(TreeNode* root) {
        if ( root -> left == NULL && root -> right == NULL ) {
            return root -> val;
        }
        bool temp;
        if ( root -> val == 2 ) {
            temp = travel(root->left) | travel(root->right);
        }
        else {
            temp = travel(root->left) & travel(root->right);
        }
        return temp;
    }
    bool evaluateTree(TreeNode* root) {
        bool ans = false;
        return travel(root);
    }
};
