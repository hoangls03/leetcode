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
    int travel(vector<int> &d, TreeNode*root) {
        if ( root == NULL ) return 0;
        d[root->val]++;
        if ( root->left == NULL && root->right == NULL ) {
            int temp = 0;
            for ( int i = 1 ; i <= 9 ; ++i ) {
                if ( d[i] & 1 ) temp++;
            }
            d[root->val]--;
            if ( temp > 1 ) return 0;
            return 1;
        }
        int left = travel(d,root->left);
        int right = travel(d,root->right);
        d[root->val]--;
        return left + right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> d(10,0);
        return travel(d,root);
    }
};
