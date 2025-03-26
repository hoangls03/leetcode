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
    private void process(TreeNode root, int curr, int[] mark) {

        if (mark[curr] < mark[root.val]) {
            if (root.left == null) {
                root.left = new TreeNode(curr);
            } else {
                if (mark[curr] < mark[root.left.val]) {
                    process(root.left, curr, mark);
                } else {
                    if (root.right == null) {
                        root.right = new TreeNode(curr);
                    } else {
                        process(root.right, curr, mark);
                    }
                }
            }
        } else {
            if (root.right == null) {
                root.right = new TreeNode(curr);
            } else {
                process(root.right, curr, mark);
            }
        }
    }
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        int n = preorder.length;
        int[] mark = new int[n + 1];

        // Marking the indices of postorder values
        for (int i = 0; i < n; ++i) {
            mark[postorder[i]] = i;
        }

        // Root is the first element of preorder
        TreeNode root = new TreeNode(preorder[0]);

        // Process the rest of the preorder array
        for (int i = 1; i < n; ++i) {
            int curr = preorder[i];
            process(root, curr, mark);
        }

        return root;
    }
}
