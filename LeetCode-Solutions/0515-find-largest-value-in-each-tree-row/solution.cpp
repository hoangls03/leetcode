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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        if ( root ) q.push(root);
        vector<int> ans;
        while ( q.size() ) {
            int n = q.size();
            int res = -2147483648;
            for ( int i = 0 ; i < n ; ++i ) {
                auto u = q.front();
                q.pop();
                res = max(res,u->val);
                if ( u -> left ) q.push(u->left);
                if ( u -> right ) q.push(u->right);
            }
            ans.push_back(res);
        }
        return ans;
    }
};
