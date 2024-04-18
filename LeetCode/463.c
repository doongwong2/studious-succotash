int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;
    int rows = gridSize;
    int cols = *gridColSize;

    for(int r = 0;r < rows;r++)
        for(int c = 0;c < cols;c++)
        {
            if(grid[r][c] == 1)
            {
                perimeter += 4;
                if(r > 0)
                    if(grid[r -1][c] == 1)
                        perimeter -=2;
                
                if(c > 0)
                    if(grid[r][c-1] == 1)
                        perimeter -=2;
            }
        }

    return perimeter;
}
