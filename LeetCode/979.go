/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func distributeCoins(root *TreeNode) int {
    var res int
    var dfs func(r *TreeNode)(minus, plus int)
    dfs = func(r *TreeNode)(minus, plus int) {
        if nil == r {return 0,0}
        lm, lp := dfs(r.Left)
        rm, rp := dfs(r.Right)

        minus, plus = lm + rm, lp + rp

        diff := r.Val -1
        if diff < 0{minus += -diff} else {plus += diff}
        minus, plus = minus - min(minus,plus), plus - min(minus, plus)
        res += minus + plus

        return minus, plus
    }
    dfs(root)
    return res
}
