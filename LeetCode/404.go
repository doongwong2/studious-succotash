/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumOfLeftLeaves(root *TreeNode) int {
    if nil == root {
        return 0
    }

    left := 0;
    if root.Left != nil && root.Left.Left == nil && root.Left.Right == nil{
        left = root.Left.Val
    }

    return left + sumOfLeftLeaves(root.Left) + sumOfLeftLeaves(root.Right)
}
