func numRescueBoats(people []int, limit int) int {
    sort.Ints(people)
    ans := 0
    s := 0

    for end := len(people) - 1; end >= s; end --{
        if people[end] == limit {
            ans++
        } else if people[end] + people[s] <= limit {
            s++
            ans++
        } else {
            ans++
        }
    }
    return ans
}
