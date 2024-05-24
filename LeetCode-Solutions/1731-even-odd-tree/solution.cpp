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
    void arrive( TreeNode *root , int rank, bool& ans, vector<int>& mark ) {
        if ( root == NULL ) return ;
        if ( rank % 2 == 0 ) {
            if ( root->val % 2 == 0 ) {
                //cout<<root->val<<" "<<rank<<'\n';
                ans = false;
                return ;
            }  
            if ( mark[rank] >= root->val ) {
                //cout<<mark[rank]<<" "<<root->val<<" "<<rank<<'\n';
                ans = false;
                return ;
            } 
            mark[rank] = root->val;
        }
        if ( rank % 2 == 1 ) {
            if ( root->val % 2 == 1 ) {
                //cout<<root->val<<" "<<rank<<'\n';
                ans = false;
                return ;
            }  
            if ( mark[rank] != 0 && mark[rank] <= root->val ) {
                //cout<<mark[rank]<<" "<<root->val<<" "<<rank<<'\n';
                ans = false;
                return ;
            } 
            mark[rank] = root -> val;
        }
        arrive(root->left,rank+1,ans,mark);
        arrive(root->right,rank+1,ans,mark);
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<int> mark(1e6,0);
        bool ans = true;
        arrive(root,0,ans,mark);
        return ans;
    }
};
