/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
    boolean travel( ListNode tmp, TreeNode root ) {
        if ( tmp == null ) return true;
        if ( root == null ) return false;
        if ( tmp.val != root.val ) return false;
        tmp = tmp.next;
        return (travel(tmp,root.left) || travel(tmp,root.right) );
    }
    public boolean isSubPath(ListNode head, TreeNode root) {
        boolean ans = travel(head,root);
        if ( ans == true ) return ans;
        if ( root == null ) return false;
        boolean l = isSubPath(head,root.left);
        boolean r = isSubPath(head,root.right);
        return ( l || r );
    }
}
