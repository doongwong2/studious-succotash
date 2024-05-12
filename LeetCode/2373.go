func largestLocal(grid [][]int) [][]int {
    n := len(grid)
    res := make([][]int, n-2)
    for i:= range res{
        res[i] = make([]int, n- 2)
    }

    for i:= 0;i < n-2; i++{
        for j:= 0;j < n-2; j++{
            for x := 0; x < 3; x++{
                for y := 0; y< 3; y++{
                    res[i][j] = max(res[i][j], grid[i + x][j + y])
                }
            }
        }
    }
    return res
}
