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
    int ans = 0;
    private int findPath(TreeNode root) {
        if ( root == null ) return 0;
        int left = findPath(root.left);
        int right = findPath(root.right);

        int leftVal = 0;
        int rightVal = 0;
        if ( root.left != null && root.left.val == root.val ) {
            leftVal = left + 1;
        }

        if ( root.right != null && root.right.val == root.val ) {
            rightVal = right + 1;
        }

        ans = Math.max(ans,leftVal + rightVal);
        int path = Math.max(leftVal,rightVal);
        return path;
    }
    public int longestUnivaluePath(TreeNode root) {
        findPath(root);
        return ans;
    }
}
