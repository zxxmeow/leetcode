# 190.Reverse Bits

## Accepted Code

**C:**

```c
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    int i = 32;
    while(i > 1)
    {
        if(n & 1 == 1)
            result = result + 1;

        result = result << 1;
        n = n >> 1;
        i--;
    }
    
    if(n & 1 == 1)
        result = result + 1;
    
    return result;
}
```

## Analysis

这个题也比较简单，就普通的用位运算即可~

注意最后循环的时候我少做了一次，留到循环外，以免多移一次造成数据丢失。