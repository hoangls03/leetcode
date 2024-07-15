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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int,TreeNode*> mp;
        map<int,int> mark;
        int n = descriptions.size();
        for ( int i = 0 ; i < n ; ++i ) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            mark[child] = 1;
            if ( mp[parent] == NULL ) {
                    TreeNode* node = new TreeNode;
                    node->val = parent;
                    mp[parent] = node;
                }
            if ( mp[child] == NULL ) {
                TreeNode* child_node = new TreeNode;
                child_node->val = child;
                mp[child] = child_node;
            }
            if ( isLeft == 1 ) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }
        }
        for ( int i = 0 ; i < n ; ++i ) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            if ( mark[parent] == 0 ) {
                return mp[parent];
            }
        }
        return NULL;
    }
};
