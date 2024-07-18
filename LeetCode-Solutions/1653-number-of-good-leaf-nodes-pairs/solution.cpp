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
    vector<int> travel(TreeNode* root, int distance, int& ans) {
        if ( root == NULL ) return {};
        if ( root->left == NULL && root->right == NULL ) return {1};
        vector<int> l_dis = travel(root->left,distance,ans);
        vector<int> r_dis = travel(root->right,distance,ans);
        for ( auto i : l_dis ) {
            for ( auto j : r_dis ) {
                if ( i + j <= distance ) ans++;
            }
        }

        vector<int> vt;
        for ( auto i : l_dis ) {
            if ( i + 1 < distance ) vt.push_back(i+1); 
        }
        for ( auto i : r_dis ) {
            if ( i + 1 < distance ) vt.push_back(i+1);
        }
        return vt;
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        vector<int> l_dis,r_dis;
        travel(root,distance,ans);
        return ans;
    }
};
