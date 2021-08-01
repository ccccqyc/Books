/**
 * 二叉树翻转
 * 比如：    源二叉树
 * 8
 * /  \
 * 6   10
 * / \  / \
 * 5  7 9 11
 * 镜像二叉树
 * 8
 * /  \
 * 10   6
 * / \  / \
 * 11 9 7  5
 * <p>
 * 深度优先算法 + 递归
 */
public class JZ18BinaryTreeMirror {
    public TreeNode Mirror(TreeNode pRoot) {
        // write code here
        TreeNode temp;
        if (pRoot != null) {
            temp = pRoot.left;
            pRoot.left = pRoot.right;
            pRoot.right = temp;
            Mirror(pRoot.left);
            Mirror(pRoot.right);
        }
        return pRoot;
    }

    private class TreeNode {
        int val;
        TreeNode left = null;
        TreeNode right = null;

        public TreeNode(int val) {
            this.val = val;
        }
    }


}
