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
#define ii pair<int,int>
#define iii pair<bool,ii>
#define fi first
#define se second
class Solution {
public:
    struct st{
        bool per;
        int lev, siz;
    };
    st travel( TreeNode* root, vector<int>& ans) {
        if ( root == NULL ) return {true,-1,0};
        if ( root -> left == NULL && root -> right == NULL ) {
            ans.push_back(1);
            return {true,0,1};
        }
        auto l = travel(root->left,ans);
        auto r = travel(root->right,ans);
        if ( root -> left == NULL || root -> right == NULL ) {
            return {false,-1,-1};
        }
        if ( !l.per || !r.per ) return {false,-1,-1};
        if ( l.lev != r.lev ) return {false,-1,-1};
        
        ans.push_back(l.siz+r.siz+1);
        return {true,l.lev+1,l.siz + r.siz + 1};
        
    }
    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> ans;
        travel(root,ans);
        sort(ans.rbegin(),ans.rend());
        if ( k > ans.size() ) return -1;
        return ans[k-1];
    }
};
