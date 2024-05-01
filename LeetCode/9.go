func isPalindrome(x int) bool {
    if x < 0{
        return false
    }
    if x < 10 {
        return true
    }
    var temp int = x
    var check int = 0

    for temp > 0 {
        check *= 10
        check += temp %10
        temp /= 10
    }

    return check == x
}
