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
    void DFS(TreeNode*root, int curDepth, vector<int>& ans, int& maxDepth) {
        if ( root == NULL ) return;
        if ( curDepth > maxDepth ) {
            while( ans.size() ) {
                ans.pop_back();
            }
            maxDepth = curDepth;
        }
        if ( curDepth == maxDepth ) {
            ans.push_back(root->val);
        }
        DFS(root->left,curDepth + 1,ans,maxDepth);
        DFS(root->right,curDepth + 1,ans,maxDepth);
    }

    int cal(TreeNode* root, TreeNode*& res, int& sum, vector<int>& mark) {
        if ( root == NULL ) return 0;
        int left = cal(root->left,res,sum,mark);
        int right = cal(root->right,res,sum,mark);
        if ( left + right + mark[root->val]== sum ) {
            if ( res == NULL ) {
                res = root;
            }
        }
        return left + right + mark[root->val];

    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<int> mark(501,0);
        vector<int> ans;
        int maxDepth = 0;
        DFS(root,0,ans,maxDepth);
        int sum = 0;
        for ( auto i : ans ) {
            mark[i] = 1;
        }
        sum = ans.size();
        TreeNode* res = NULL;
        cal(root,res,sum,mark);
        return res;
        
    }
};
