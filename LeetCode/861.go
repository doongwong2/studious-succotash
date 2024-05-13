func matrixScore(grid [][]int) int {
    n := len(grid)
    m := len(grid[0])

    res := n * (1 << (m -1))
    for j := 1;j < m;j++ {
        cnt := 0
        for i:= 0;i < n; i++ {
            if grid[i][0] == 1{
                cnt += grid[i][j]
            } else {
                cnt += 1 - grid[i][j]
            }
        }
        cnt = max(cnt, n - cnt)
        res += cnt * (1 << (m - 1 - j))
    }
    return res
}
