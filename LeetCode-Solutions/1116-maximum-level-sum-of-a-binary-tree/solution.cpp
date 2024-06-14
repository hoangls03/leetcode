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
    void travel(TreeNode* root, int level, vector<int>& sum, int& max_level) {
        if ( root == NULL ) return ;
        max_level = max(max_level,level);
        sum[level] += root->val;
        travel(root->left,level+1,sum,max_level);
        travel(root->right,level+1,sum,max_level);
    }
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int max_level = 1;
        vector<int> sum(1e4+5,0);
        travel(root,level,sum,max_level);
        int ans = 1;
        int save = -1e9;
        for ( int i = 1 ; i <= max_level ; ++i ) {
            if ( sum[i] > save ) {
                ans = i;
                save = sum[i];
            }
        }
        return ans;
    }
};
