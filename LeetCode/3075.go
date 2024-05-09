func maximumHappinessSum(happiness []int, k int) int64 {
    sort.Slice(happiness, func(i,j int)bool {
        return happiness[i] > happiness[j]
    })

    var res int64 = 0
    for i := 0; i< len(happiness) && i < k; i++ {
        if happiness[i] <= i{
            break
        }
        res += int64(happiness[i] - i)
    }
    return res
}
