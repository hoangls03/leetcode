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
    void travel( TreeNode* node, vector<vector<int>>& vt) {
        if ( node == NULL ) return;
        if ( node->left != NULL ) {
            vt[node->left->val].push_back(node->val);
            vt[node->val].push_back(node->left->val);
        }
        if ( node -> right != NULL ) {
            vt[node->right->val].push_back(node->val);
            vt[node->val].push_back(node->right->val);
        }
        travel(node->left,vt);
        travel(node->right,vt);
    }
    void BFS( int start, vector<vector<int>>& vt, vector<int>& mark ) {
        queue<int> q;
        q.push(start);
        mark[start] = 0;
        while ( !q.empty() ) {
            int u = q.front();
            q.pop();
            for ( auto v : vt[u] ) {
                if ( mark[v] == -1 ) {
                    mark[v] = mark[u] + 1;
                    q.push(v);
                }
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        vector< vector<int> > vt(1e5+1);
        vector<int> mark(1e5+1,-1);
        travel(root,vt);
        BFS(start,vt,mark);
        int ans = 0;
        for ( int i = 1 ; i <= 1e5 ; ++i ) {
            ans = max(ans,mark[i]);
        }
        return ans;
    }
};
