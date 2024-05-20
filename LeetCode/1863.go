func subsetXORSum(nums []int) int {
    sum := 0

    for i := 0;i < len(nums);i++ {
        sum |= nums[i]
    }

    sum = (sum << (len(nums) -1))

    return sum
}
