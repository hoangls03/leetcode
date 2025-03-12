/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int maxLevel = 0, ans = 0;
    private void travel( TreeNode root, int level ) {
        if ( root == null ) return ;
        if ( level > maxLevel ) {
            ans = root.val;
            maxLevel = level;
        } else if ( level == maxLevel ) {
            ans += root.val;
        }
        travel(root.left,level + 1);
        travel(root.right,level + 1);
    }
    public int deepestLeavesSum(TreeNode root) {
        travel(root,0);
        return ans;
    }
}
