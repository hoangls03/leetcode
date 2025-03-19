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
import java.util.Collections;
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> s = new LinkedList<>();
        List<List<Integer>> ans = new ArrayList<>();
        if ( root == null) return ans;
        s.add(root);
        int level = 1;
        while ( s.size() != 0 ) {
            int n = s.size();
            List<Integer> tmp = new ArrayList<>(n);
            for ( int i = 0 ; i < n ; ++i ) {
                TreeNode cur = s.peek(); 
                s.remove();
                if ( level % 2 == 1 ) tmp.addLast(cur.val);
                else tmp.addFirst(cur.val);
                if ( cur.left != null ) {
                    s.add(cur.left);
                }
                if ( cur.right != null ) {
                    s.add(cur.right);
                }
            }
            ans.add(tmp);
            level++;
        }
        
        return ans;
    }
}
