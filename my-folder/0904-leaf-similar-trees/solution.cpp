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
    void travel( TreeNode* node, vector<int>& vt ) {
        if ( node ==  NULL ) return;
        if ( node->left == NULL && node->right == NULL ) {
            vt.push_back(node->val);
            return;
        }
        if ( node->left != NULL ) travel(node->left,vt);
        if ( node -> right != NULL ) travel(node->right,vt);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vt1,vt2;
        travel(root1,vt1);
        travel(root2,vt2);
        if ( vt1.size() != vt2.size() ) return false;
        for ( int i = 0 ; i < vt1.size() ; ++i ) {
            if ( vt1[i] != vt2[i] ) return false;
        }
        return true;
    }
};
