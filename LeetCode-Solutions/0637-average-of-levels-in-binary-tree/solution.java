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
    public List<Double> averageOfLevels(TreeNode root) {
        Queue<TreeNode> s = new LinkedList<>();
        List<Double> ans = new ArrayList<>();

        s.add(root);
        
        Double sum = 0.0;
        while ( s.size() != 0 ) {
            int n = s.size();
            sum = 0.0;
            for ( int i = 0 ; i < n ; ++i ) {
                TreeNode cur = s.peek(); 
                s.remove();
                sum += cur.val;
                if ( cur.left != null ) {
                    s.add(cur.left);
                }
                if ( cur.right != null ) {
                    s.add(cur.right);
                }
            }
            ans.add(sum/n);
        }
        
        return ans;
    }
}
