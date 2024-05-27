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
    void travel(TreeNode* root, int target, int& ans, long long sum, map<long long,int> &mp  ) {
        if ( root == NULL ) return ;
        sum += root->val;
        if ( sum == target ) ans++;
        ans += mp[sum-target];
        mp[sum]++;
        travel(root->left,target,ans,sum,mp);
        travel(root->right,target,ans,sum,mp);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        map<long long,int> mp;
        mp.clear();
        travel(root,targetSum,ans,0,mp);
        return ans;
    }
};
