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
#define ii pair<int,int>
#define fi first
#define se second
class Solution {
public:
    ii travel(TreeNode* root, int& ans) {
        if ( root == NULL ) {
            return {0,0};
        }
        auto left = travel(root->left,ans);
        auto right = travel(root->right,ans);
        int curSum = left.fi + right.fi + root->val;
        int curNum = left.se + right.se + 1;
        if ( curSum/curNum == root->val ) {
            ans++;
        }
        return {curSum,curNum};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        travel(root,ans);
        return ans;
    }
};
