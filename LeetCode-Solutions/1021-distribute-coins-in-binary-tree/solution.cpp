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
    int travel( TreeNode* root, int& ans ) {
        if ( root == NULL ) return 0;
        int left_excess = travel(root->left,ans);
        int right_excess = travel(root->right,ans);
        int excess = root->val - 1 + left_excess + right_excess;
        ans += abs(left_excess) + abs(right_excess);
        return excess;
    }
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        travel(root,ans);
        return ans;
    }
};
