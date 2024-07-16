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
 #define ic pair<int,char>
 #define fi first
 #define se second
class Solution {
public:
    void travel(TreeNode* root, vector<vector<ic>>& g) {
        if ( root == NULL ) return;
        int val = root->val;
        if ( root->left != NULL ) {
            int left_val = root->left->val;
            g[val].push_back({left_val,'L'});
            g[left_val].push_back({val,'U'});
            
        }
        if ( root->right != NULL ) {
            int right_val = root->right->val;
            g[val].push_back({right_val,'R'});
            g[right_val].push_back({val,'U'});
        }
        travel(root->left,g);
        travel(root->right,g);
    }
    void find_size(TreeNode* root, int& n ) {
        if ( root == NULL ) return ;
        n = max(n,root->val);
        find_size(root->left,n);
        find_size(root->right,n);
    }
    void DFS(int u, int destValue, string& path, string& ans, vector<int>& mark, vector<vector<ic>>& g ) {
        mark[u] = 1;
        if ( u == destValue && ans == "" ) ans = path;
        for ( auto v : g[u] ) {
            if ( mark[v.fi] == 0 && ans == "" ) {
                path += v.se;
                if ( v.fi == destValue ) ans = path; 
                mark[v.fi] = 1;
                DFS(v.fi,destValue,path,ans,mark,g);
                path.pop_back();
            }
            
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        int n = 0;
        find_size(root,n);
        vector<vector<ic>> g(n+5);
        travel(root,g);
        vector<int> mark(n+5,0);
        string ans = "";
        string path = "";
        DFS(startValue,destValue,path,ans,mark,g);
        g.clear();
        return ans;
    }
};
