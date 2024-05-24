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
    void travel( TreeNode* root, string& ans , string s) {
        if ( root == NULL ) return ;
        s = char(root->val + 'a') + s;
        if ( root -> left == NULL && root -> right == NULL ) {
            if ( ans.size() == 0 ) ans = s;
            else if ( s < ans ) ans = s;
        }
        travel(root->left,ans,s);
        travel(root->right,ans,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        string ans = "";
        travel(root,ans,"");
        return ans;
    }
};
