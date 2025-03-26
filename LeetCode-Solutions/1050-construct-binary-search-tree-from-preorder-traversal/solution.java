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
    int pos = 0;
    private TreeNode travel(int [] preorder, int low, int high ) {
        if ( pos >= preorder.length ) {
            return null;
        }
        int curVal = preorder[pos];
        if ( low <= curVal && curVal <= high ) {
            pos++;
            TreeNode cur = new TreeNode(curVal);
            cur.left = travel(preorder,low,curVal);
            cur.right = travel(preorder,curVal,high);
            return cur;
        }
        return null;
    }   
    public TreeNode bstFromPreorder(int[] preorder) {
        return travel(preorder,Integer.MIN_VALUE,Integer.MAX_VALUE);
    }
}
