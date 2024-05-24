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
    int cal( TreeNode* root , int &temp ) {
        if ( root == NULL ) return 0;
        int left_height = cal(root->left,temp);
        int right_height = cal(root->right,temp);
        temp = max(temp,left_height + right_height + 1);
        return max(left_height,right_height) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        cal(root,ans);
        return ans-1;
    }
};
