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
    int travel( TreeNode* root, int& ans ) {
        if ( root == NULL ) return 1e6;
        int temp = min(travel(root->left,ans),travel(root->right,ans));
        if ( temp == 1e6 ) temp = root->val;
        cout<<root->val<<" "<<temp<<'\n';
        ans = max(ans,abs(root->val - temp));
        return min(temp,root->val);
    }
    int travelmax( TreeNode* root, int& ans ) {
        if ( root == NULL ) return -1;
        int temp = max(travelmax(root->left,ans),travelmax(root->right,ans));
        if ( temp == -1 ) temp = root->val;
        ans = max(ans,abs(root->val - temp));
        return max(temp,root->val);
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans = -1;
        travel(root,ans);
        travelmax(root,ans);
        return ans;
    }
};
