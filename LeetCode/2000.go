func reversePrefix(word string, ch byte) string {
    var a string;
    for i := 0;i < len(word) ;i++{
        if word[i] == ch{
            ch_index := i;
            for i >= 0 {
                a += string(word[i])
                i--
            }
            return a + word[ch_index + 1 :]
        }
    }
    return word
}
