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
    void inorder_travel(TreeNode* root, vector<TreeNode*>& treeToSegment) {
        if ( root == NULL ) return ;
        inorder_travel(root->left,treeToSegment);
        treeToSegment.push_back(root);
        inorder_travel(root->right,treeToSegment);

    }
    TreeNode* segmentToTree(int l, int r,vector<TreeNode*>& treeToSegment) {
        if ( l > r ) return NULL;
        int mid = ( l + r ) >> 1;
        TreeNode* root = treeToSegment[mid];
        root->left = segmentToTree(l,mid-1,treeToSegment);
        root->right = segmentToTree(mid+1,r,treeToSegment);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> treeToSegment;
        inorder_travel(root,treeToSegment);
        int n = treeToSegment.size();
        TreeNode* ans = segmentToTree(0,n-1,treeToSegment);
        return ans;
    }
};
