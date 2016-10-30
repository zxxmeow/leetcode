#include<stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main()
{
    int *digits, *returnSize;
    int digitsSize;
    
    digitsSize = 1;
    digits = malloc(sizeof(int) * digitsSize);
    digits[0] = 0;
    *returnSize = 1;
    
    printf("%d", plusOne(digits, digitsSize, returnSize)[0]);
    
    system("pause");
    return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i , c = 0;
    int *result = NULL;
    result = malloc(sizeof(int) * *returnSize);
    
    if((result[*returnSize - 1] = digits[digitsSize - 1] + 1) == 10)
    {
        result[*returnSize - 1] = 0;
        c = 1;
    }
    
    for(i = 2; i <= digitsSize; i++)
    {
        if(c == 1)
        {
            if((result[*returnSize - i] = digits[digitsSize - i] + 1) == 10)
            {
                result[*returnSize - i] = 0;
            }
            else
                c = 0;
        }
        else
            result[*returnSize - i] = digits[digitsSize - i];
    }
    
    return result;
}
