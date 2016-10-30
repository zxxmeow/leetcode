#include<stdio.h>

int** generate(int numRows, int** columnSizes) {
    int **result = NULL;
    int i, j;
    
    if(numRows == 0)
        return result;
        
    result = malloc(sizeof(int *) * numRows);
    columnSizes = malloc(sizeof(int *) * numRows);
    
    columnSizes[0] = malloc(sizeof(int));
    columnSizes[0][0] = 1;
    result[0] = malloc(sizeof(int));
    result[0][0] = 1;
    for(i = 1; i < numRows; i++)
    {
        columnSizes[i] = malloc(sizeof(int));
        *columnSizes[i] = i + 1;
        result[i] = malloc(sizeof(int) * *columnSizes[i]);
        result[i][0] = 1;
        result[i][i] = 1;
        for(j = 1; j < i; j++)
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    
    return result;
}

int main(){
    int numRows;
    int **columnSizes, **result;
    
    numRows = 1;
    result = generate(numRows, columnSizes);
    
    free(result);
    free(columnSizes);
    
    system("pause");
    return 0;
}
