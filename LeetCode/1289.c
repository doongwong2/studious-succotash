int minRow(int *arr, int arrSize, int j)
{
    int min = 20000;
    
    for(int i = 0;i < arrSize;i++)
    {
        if(arr[i] < min && i != j)
            min = arr[i];
    }
    return min;
}

int minFallingPathSum(int** grid, int gridSize, int* gridColSize) {
    if(gridSize == 1) return grid[0][0];

    int min = 20000;

    for(int i  =1;i < gridSize;i++)
    {
        for (int j = 0;j < *gridColSize;j++)
        {
            grid[i][j] += minRow(grid[i - 1], *gridColSize, j);
            if(i == gridSize - 1)
                min = grid[i][j] < min ? grid[i][j]: min;
        }
    }

    return min;
}
