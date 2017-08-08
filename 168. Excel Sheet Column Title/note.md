# 168. Excel Sheet Column Title

## Accepted Code

**C:**

```c
char* convertToTitle(int n) {
    int i, j;
    int k = 0;
    char *result;
    
    result = malloc(sizeof(char) * 100);
    while(n != 0)
    {
        i = n % 26;
        n = (n - 1) / 26;
        
        for(j = k; j > 0; j--)
            result[j] = result[j - 1];
        if(i == 0)
            result[j] = 'Z';
        else
            result[j] = 'A' + i - 1;
        k++;
    }
    
    return result;
}
```

## Analysis

给Excel表编列名，总感觉这个题似曾相识。。。。总体来说还是比较简单的，用到一个对26的整除取余和头插法。主要需要注意整除和取余，因为余数变化是 `1~15,0` 一套循环，需要注意那个`0` 是 `Z` ，另外就是除的时候在临界处(26)需要注意商的变化。
