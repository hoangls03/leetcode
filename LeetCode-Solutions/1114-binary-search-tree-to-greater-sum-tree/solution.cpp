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
    vector<int> value;

    void travel(TreeNode* root) {
        if ( root == NULL ) return ;
        value.push_back(root->val);
        travel(root->left);
        travel(root->right);
    }
    void modify_tree(TreeNode* root, vector<int> &mark) {
        if ( root == NULL ) return ;
        root -> val = mark[root->val];
        modify_tree(root->left,mark);
        modify_tree(root->right,mark);
    }
    TreeNode* bstToGst(TreeNode* root) {
        value.clear();
        travel(root);
        sort(value.begin(),value.end());
        int n = value.size();
        int sum = 0;
        vector<int> mark(10000,0);
        for (int i = n - 1 ; i >= 0 ; --i ) {
            sum += value[i];
            cout<<value[i]<<" "<<sum<<'\n';
            mark[value[i]] = sum;
        }
        modify_tree(root,mark);
        return root;
    }
};
