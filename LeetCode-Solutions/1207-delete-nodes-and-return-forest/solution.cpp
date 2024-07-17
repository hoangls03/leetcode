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
    void travel(TreeNode*& root, vector<int>& mark, vector<TreeNode*>& ans ) {
        if ( root == NULL ) return ;
        if ( root->left != NULL ) {
            if ( mark[root->val] == 1 ) {
                if ( mark[root->left->val] == 0 ) {
                    ans.push_back(root->left);
                }
            }
            travel(root->left,mark,ans);
        }
        if ( root->right != NULL ) {
            if ( mark[root->val] == 1 && mark[root->right->val] == 0 ) {
                ans.push_back(root->right);
            }
            travel(root->right,mark,ans);
        }
        if ( mark[root->val] == 1 ) {
            root = NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        vector<int> mark(1005,0);
        for ( auto i : to_delete ) {
            mark[i] = 1;
        }
        if ( mark[root->val] == 0 ) ans.push_back(root);
        travel(root,mark,ans);
        return ans;
    }
};
