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
class FindElements {
public:
    vector<bool> mark;

    FindElements(TreeNode* root) : mark(1e6 + 1, false) {
        root->val = 0;
        travel(root);
    }

    void travel(TreeNode* root ) {
        if ( root -> left != NULL ) {
            root -> left -> val = 2*root->val + 1;
            travel(root->left);
        }    
        if ( root -> right != NULL ) {
            root -> right -> val = 2*root->val + 2;
            travel(root->right);
        }
        if ( root -> val >= 0 && root -> val <= 1e6 ) {
            mark[root->val] = true;
        }
        
    }
    
    bool find(int target) {
        return mark[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
