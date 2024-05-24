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
    void arrive( TreeNode* root, int rank, int& ans, int &max_rank ) { 
        if ( root == NULL ) return ;
        rank++;
        //cout<<rank<<" "<<root->val<<'\n';
        if ( rank > max_rank ) {
            ans = root -> val;
            max_rank = rank;
        }
        arrive(root->left,rank,ans,max_rank);
        arrive(root->right,rank,ans,max_rank);
    } 
    int findBottomLeftValue(TreeNode* root) {
        int ans,max_rank = 0;
        arrive(root,0,ans,max_rank);
        return ans;
    }
};
