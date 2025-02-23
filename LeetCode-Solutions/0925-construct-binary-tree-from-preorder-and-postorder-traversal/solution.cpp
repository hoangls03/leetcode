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
    void process(TreeNode* &root, int curr, vector<int>& mark ) {
        if ( mark[curr] < mark[root->val] ) {
            if ( root -> left == NULL ) {
                root -> left = new TreeNode(curr);
            } else {
                if ( mark[curr] < mark[root->left->val] )
                    process(root->left,curr,mark);
                else {
                    if ( root -> right == NULL ) {
                        root -> right = new TreeNode(curr);
                    } else {
                        process(root->right,curr,mark);
                    }
                }
            }
        } else {
            if ( root -> right == NULL ) {
                root -> right = new TreeNode(curr);
            } else {
                process(root->right,curr,mark);
            }
        }
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        vector<int> mark(n+1,0);
        for ( int i = 0 ; i < n; ++i ) {
            mark[postorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        for ( int i = 1 ; i < n ; ++i ) {
            int curr = preorder[i];
            process(root,curr,mark);
        }
        return root;
    }
};
