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
    TreeNode* add(TreeNode* root, int val, int depth, int height ) {
        if ( root == NULL ) return nullptr;
        if ( height == depth - 1 ) {
            TreeNode* left_tree = root -> left;
            TreeNode* right_tree = root -> right;
            root->left = new TreeNode(val);
            root -> right = new TreeNode(val);
            root->left->left = left_tree;
            root->right->right = right_tree;
            
            return root;
        }

        root -> left = add(root->left,val,depth,height + 1);
        root -> right = add(root->right,val,depth,height + 1);

        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if ( depth == 1 ) {
            TreeNode* temp = new TreeNode(val);
            temp -> left = root;
            return temp;
        }
        return add(root,val,depth,1);
    }
};
