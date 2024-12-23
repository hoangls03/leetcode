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
#define fi first
#define se second
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while ( q.size() ) {
            vector<int> vt;
            int n = q.size();
            for ( int i = 0 ; i < n ; ++i ) {
                auto u = q.front();
                vt.push_back(u->val);
                q.pop();
                if ( u -> left ) q.push(u->left);
                if ( u -> right ) q.push(u->right);
            }
            map<int,int> mp;
            vector<int> save;
            for ( int i = 0 ; i < n ; ++i ) {
                save.push_back(vt[i]);
                mp[vt[i]] = i;
            }
            sort(save.begin(),save.end());
            for ( int i = 0 ; i < n ; ++i ) {
                if ( vt[i] != save[i] ) {
                    ans++;
                    mp[vt[i]] = mp[save[i]];
                    swap(vt[i],vt[mp[save[i]]]);
                }
            }
        }
        return ans;
    }
};
