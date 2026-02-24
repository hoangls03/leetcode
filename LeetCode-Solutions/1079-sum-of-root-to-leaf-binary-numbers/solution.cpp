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
    void travel(TreeNode* root, int cur, int& ans ) {
        if ( root == NULL ) {
            return ;
        }
        cur = cur*2 + root->val;
        if ( root->left == NULL && root->right == NULL ) {
            ans += cur;
        }
        travel(root->left,cur,ans);
        travel(root->right,cur,ans);
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        travel(root,0,ans);
        return ans;
    }
};
