type Queue[T any] []T

func NewQueue[T any]() Queue[T] {
	return make([]T, 0)
}

func (q *Queue[T]) Push(v T) {
	*q = append(*q, v)
}

func (q *Queue[T]) Pop() T {
	old := *q
	x := old[0]
	*q = old[1:]
	return x
}

func (q *Queue[T]) Len() int {
	return len(*q)
}

type Matrix[T any] struct {
	data       [][]T
	defaultVal T
}

func NewSquare[T any](n int, defaultVal ...T) *Matrix[T] {
	data := make([][]T, n)
	for i := range data {
		data[i] = make([]T, n)
		if len(defaultVal) > 0 {
			for j := range data[i] {
				data[i][j] = defaultVal[0]
			}
		}
	}
	mat := &Matrix[T]{
		data: data,
	}

	if len(defaultVal) > 0 {
		mat.defaultVal = defaultVal[0]
	}
	return mat
}

func (mat *Matrix[T]) At(i, j int) T {
	if !mat.InBound(i, j) {
		return mat.defaultVal
	}
	return mat.data[i][j]
}

func (mat *Matrix[T]) InBound(i, j int) bool {
	if i < 0 || i >= len(mat.data) {
		return false
	}
	if len(mat.data) > 0 && (j < 0 || j >= len(mat.data[0])) {
		return false
	}
	return true
}

func (mat *Matrix[T]) UpdateAt(i, j int, val T) {
	if !mat.InBound(i, j) {
		return
	}
	mat.data[i][j] = val
}

func (mat *Matrix[T]) ForEach(f func(val T, i, j int)) {
	for i := range mat.data {
		for j := range mat.data[i] {
			f(mat.data[i][j], i, j)
		}
	}
}

func (mat *Matrix[T]) Data() [][]T {
	return mat.data
}

type pos struct {
    i, j int
}

var dir = []pos{{0,1},{1,0},{0,-1},{-1,0}}

func maximumSafenessFactor(grid [][]int) int {
    n := len(grid)
    mat := NewSquare[int](n)
    qThiefPos := NewQueue[pos]()
    mat.ForEach(func(_, i, j int) {
        if grid[i][j] == 0 {
            mat.UpdateAt(i,j, math.MaxInt64)
        } else {
            mat.UpdateAt(i, j, 1)
            qThiefPos.Push(pos{i,j})
        }
    })

    ans := math.MaxInt64
    level :=  2
    for qThiefPos.Len() > 0{
        for n:= qThiefPos.Len(); n > 0; n-- {
            floodPos := qThiefPos.Pop()
            for _, d := range dir{
                x,y := floodPos.i + d.i, floodPos.j + d.j
                if mat.InBound(x,y) && mat.At(x,y) > level {
                    mat.UpdateAt(x,y,level)
                    qThiefPos.Push(pos{x,y})
                }
            }
        }
        level ++
    }

    l, h := 0, level -1
    for l <= h {
        m:= (l + h) /2
        if isPathAbleToExist(mat,m){
            ans, l = m, m + 1
        } else {
            h  = m - 1
        }
    }
    return ans -1
}

func isPathAbleToExist(mat *Matrix[int], lowestLevel int) bool {
    n := len(mat.Data())
    vis := NewSquare[bool](n)
    bfsQueue := NewQueue[pos]()
    if mat.At(0,0) >= lowestLevel {
        bfsQueue.Push(pos{0,0})
    }
    vis.UpdateAt(0,0,true)

    for bfsQueue.Len() > 0{
        bfsPos := bfsQueue.Pop()
        if bfsPos.i == n -1 && bfsPos.j == n-1 {
            return true
        }
        for _, d := range dir{
            x,y := bfsPos.i + d.i, bfsPos.j + d.j
            if mat.InBound(x,y) && !vis.At(x,y) && mat.At(x,y) >= lowestLevel {
                vis.UpdateAt(x,y, true)
                bfsQueue.Push(pos{x,y})
            }
        }
    }
    return false
}
