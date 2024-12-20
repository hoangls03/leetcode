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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int odd = 0 ;
        while ( q.size() ) {
            int n = q.size();
            vector<TreeNode*> vt(n);
            for ( int i = 0 ; i < n ; ++i ) {
                auto u = q.front();
                q.pop();
                if ( u->left ) q.push(u->left);
                if ( u->right ) q.push(u->right);
                if ( odd & 1) {
                    vt[i] = u;
                }
            }
            if ( odd & 1 ) {
                for ( int i = 0 ; i < n/2 ; ++i ) {
                    swap(vt[i]->val,vt[n-i-1]->val);
                }
            }
            odd++;
        }
        return root;
    }
};
