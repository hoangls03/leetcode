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
    int travel( TreeNode* root, vector<int>& mark, int level, vector<int>& count, vector<int>& height, vector<int>& secondHeight ) {
        if ( root == NULL ) return -1;
        int l = travel(root->left,mark,level+1,count,height,secondHeight);
        int r = travel(root->right,mark,level+1,count,height,secondHeight);
        int cur = max(l,r) + 1 + level;
        mark[root->val] = level;
        if ( height[level] != 0 ) {
            if ( cur >= height[level] ) {
                secondHeight[level] = height[level];
                count[level] = root->val;
                height[level] = cur;
            } else if ( cur > secondHeight[level] ) {
                secondHeight[level] = cur;
            }
        } else {
            count[level] = root -> val;
            height[level] = cur;
        }
        return max(l,r) + 1;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> mark(1e5+1,0),count(1e5+1,0),height(1e5+1,0),secondHeight(1e5+1,0);
        travel(root,mark,0,count,height,secondHeight);
        vector<int> ans;
        for ( auto i : queries ) {
            int level = mark[i];
            if ( count[level] == i ) {
                if ( secondHeight[level] != 0 ) ans.push_back(secondHeight[level]);
                else ans.push_back(mark[i]-1);
            }
            else ans.push_back(height[level]);
        }      
        return ans;
    }
};
