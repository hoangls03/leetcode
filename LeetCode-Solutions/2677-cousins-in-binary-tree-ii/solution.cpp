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
    void calculateSum( TreeNode* root, vector<int>& sum, int level ) {
        if ( root == NULL ) return ;
        if ( sum.size() < level + 1 ) {
            sum.push_back(root->val);
        } else {
            sum[level] += root->val;
        }
        calculateSum(root->left,sum,level+1);
        calculateSum(root->right,sum,level+1);
    }
    void calculateNode( TreeNode* root, vector<int>& sum, int level ) {
        if ( root == NULL ) return ;
        int l_val = 0;
        if ( root -> left != NULL ) {
            l_val = root -> left -> val;
        }
        int r_val = 0;
        if ( root -> right != NULL ) {
            r_val = root -> right -> val;
        }
        if ( root -> left != NULL ) {
            root -> left -> val = sum[level+1] - l_val - r_val;
        }
        if ( root -> right != NULL ) {
            root -> right -> val = sum[level+1] - l_val - r_val;
        }
        calculateNode(root->left,sum,level+1);
        calculateNode(root->right,sum,level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> sum;
        calculateSum(root,sum,0);
        root -> val = 0;
        calculateNode(root,sum,0);
        return root;
    }
};
