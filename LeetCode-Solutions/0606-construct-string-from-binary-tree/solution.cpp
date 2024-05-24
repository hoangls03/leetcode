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
    void traversal(TreeNode* root, string& ans) {
        if ( root == NULL ) {
            return;
        }
        int temp = abs(root->val);
        stack<int> st;
        while ( temp > 0 ) {
            st.push(temp%10);
            temp /= 10;
        }
        if ( root -> val == 0 ) ans += '0';
        if ( root -> val < 0 ) {
            ans += '-';
        }
        while ( !st.empty() ) {
            ans += st.top() + '0';
            st.pop();
        }
        if ( root -> left == NULL && root -> right == NULL ) return;
        ans += '(';
        traversal(root -> left,ans);
        ans += ')';
        if ( root -> right != NULL ) {
            ans += '(';
            traversal(root -> right,ans);
            ans += ')';
        }
    }
    string tree2str(TreeNode* root) {
        string ans;
        traversal(root,ans);
        return ans;
    }
};
