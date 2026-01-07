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
const int oo = 1e9 + 7;
class Solution {
public:
    void DFS( TreeNode* root, long long& sum ) {
        if ( root == NULL ) return ;
        sum += root->val;
        DFS(root->left,sum);
        DFS(root->right,sum);
    }
    int cal( TreeNode* root, long long& sum, long long& ans ) {
        if ( root == NULL ) return 0;
        long long left = cal(root->left,sum,ans);
        long long right = cal(root->right,sum,ans);
        long long val = left + right + root->val;
        ans = max(ans,val*(sum - val));
        return val;
    }
    int maxProduct(TreeNode* root) {
        long long sumTree = 0,ans = 0;
        DFS(root,sumTree);
        cal(root,sumTree,ans);
        return ans % oo;
    }
};
