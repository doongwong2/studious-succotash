func compareVersion(v1 string, v2 string) int {
    v1 += "."
    v2 += "."

    versions1 := make([]string, 1, len(v1))
    versions2 := make([]string, 1, len(v1))
    var i1, i2, compared int

    for i := 0 ;i < len(v1) || i < len(v2);i++{
        if i < len(v1){
            if v1[i] == '.' {
                i1++
                versions1 = append(versions1, "")
            } else {
                versions1[i1] += v1[i : i + 1]
            }
        }

        if i < len(v2){
            if v2[i] == '.' {
                i2++
                versions2 = append(versions2, "")
            } else {
                versions2[i2] += v2[i : i+ 1]
            }
        }

        if(i1 > compared && i2 > compared) ||
            (i1 > compared && i > len(v2)) ||
            (i2 > compared &&  i > len(v1)) {
                var a,b int
                if i1 > compared {
                    a, _ = strconv.Atoi(versions1[compared])
                }
                if i2 > compared {
                    b, _ = strconv.Atoi(versions2[compared])
                }

                if a > b{
                    return 1
                }
                if b > a{
                    return -1
                }
                compared++
            }
    }
    return 0
}
