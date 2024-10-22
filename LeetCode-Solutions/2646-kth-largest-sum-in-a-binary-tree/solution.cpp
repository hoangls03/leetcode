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
    void travel( TreeNode* root, vector<long long>& sum, int level ) {
        if ( root == NULL ) return;
        if ( level + 1 > sum.size() ) {
            sum.push_back(root->val);
        } else {
            sum[level] += root->val;
        }
        travel(root->left,sum,level+1);
        travel(root->right,sum,level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum;
        travel(root,sum,0);
        sort(sum.rbegin(),sum.rend());
        if ( k > sum.size() ) return -1;
        return sum[k-1];
    }
};
