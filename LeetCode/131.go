func partition(s string) [][]string {
    n := len(s)
    var res [][]string
    var curr []string
    backTrack(s, 0 ,1, curr, &res , n)
    return res
}

func backTrack(s string, beg, length int, curr []string, res *[][]string, n int){
    if beg == n {
        currCopy := make( []string, len(curr))
        copy(currCopy, curr)
        *res = append(*res, currCopy)
        return
    }
    if beg + length > n {
        return
    }

    backTrack(s, beg, length + 1, curr, res, n)

    if isPalindrome(s[beg : beg + length]) {
        curr = append(curr, s[beg: beg + length])
        backTrack(s, beg + length, 1, curr, res, n)
        curr = curr[:len(curr) -1]
    }
}

func isPalindrome(s string) bool {
    beg, end := 0, len(s) -1
    for beg < end {
        if s[beg] != s[end] {
            return false
        }
        beg++
        end--
    }
    return true
}
