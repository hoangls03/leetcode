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
    Pair<Integer,Integer> travel( TreeNode root ) {
        if ( root == null ) return new Pair<Integer, Integer>(0, 0);
        Pair<Integer,Integer> left = travel(root.left);
        Pair<Integer,Integer> right = travel(root.right);
        int value = left.getKey() + right.getKey() + root.val;
        int num = left.getValue() + right.getValue() + 1;
        int res = value/num;
        if ( res == root.val ) ans++;
        return new Pair<Integer, Integer>(value, num);
    }
    public int averageOfSubtree(TreeNode root) {
        travel(root);
        return ans;
    }
}
