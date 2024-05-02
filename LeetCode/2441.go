func findMaxK(nums []int) int {
    ht := make(map[int]bool, len(nums))

    ans := -1

    for _, num := range nums{
        ht[num] = true
        if _, ok := ht[-num]; ok {
            ans = max(ans, int(math.Abs(float64(num))))
        }
    }

    return ans
}
