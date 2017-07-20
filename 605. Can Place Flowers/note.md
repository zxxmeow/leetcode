# 605.Can Place Flowers

## Accepted Code

**C:**

```c
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int i;
    int zero = 1;
    
    for(i = 0; i < flowerbedSize; i++)
    {
        if(n == 0)
            return true;
        
        if(flowerbed[i] == 0)
        {
            zero++;
            if(zero == 3)
            {
                zero = 1;
                n--;
            }
        }
        else
            zero = 0;
    }
    
    if(flowerbed[flowerbedSize - 1] == 0 && zero == 2 && n == 1 || n == 0)
        return true;
    
    return false;
}
```

## Analysis

居然超过了100%的人？！神奇！

就判断是否有连续的3个0即可，此时可种下一朵花。另外注意一下首尾只需要连着两个0即可。