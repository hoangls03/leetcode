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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int pos = 0;
        int n = traversal.size();
        while ( pos < n ) {
            int depth = 0;
            while ( pos < n && traversal[pos] == '-' ) {
                pos++;
                depth++;
            }
            int num = 0;
            while ( pos < n && '0' <= traversal[pos] && traversal[pos] <= '9' ) {
                num = num*10 + traversal[pos] - '0';
                pos++;
            }
            while ( st.size() > depth ) {
                st.pop();
            }

            TreeNode* temp = new TreeNode(num);
            if ( st.size() ) {
                if ( st.top() -> left == NULL ) {
                    st.top() -> left = temp;
                } else {
                    st.top() -> right = temp;
                }
            }

            st.push(temp);
        }

        while ( st.size() > 1 ) {
            st.pop();
        }

        return st.top();
    }
};
