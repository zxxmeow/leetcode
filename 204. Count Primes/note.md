# 204. Count Primes

## Accepted Code

**C:**

```c
int countPrimes(int n) {
    bool array[n + 1];
    int result = 0;
    int i, j;
    
    for(i = 0; i <= n; i++)
        array[i] = false;
    
    i = 2;
    while(i * i < n)
    {
        if(array[i] == false)
        {
            result++;
            for(j = i*i; j <= n; j = j + i)
                array[j] = true;
        }
        i++;
    }
    
    while(i < n)
    {
        if(array[i] == false)
            result++;
        i++;
    }
    
    return result;
}
```

## Analysis

比较经典的查素数的题，提前看了一下hint，还是很有收获的，了解了一个经典找素数的算法 [Sieve of Eratosthenes](http://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)，此方法适用于找 **n以内的所有素数** ，此算法即从 `2` 开始遍历到 `√n` ，对于每一个数字，将其倍数确定为合数，而在遍历过程中直到遍历结束，所有未被标为合数的均为素数。

![](https://leetcode.com/static/images/solutions/Sieve_of_Eratosthenes_animation.gif)

