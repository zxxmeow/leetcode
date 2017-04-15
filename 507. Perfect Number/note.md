# 507.Perfect Number

## Accepted Code

**C:**

```c
bool checkPerfectNumber(int num) {
    int i = 1;
    int sum = 0;
    
    if(num == 0)
        return false;
    
    while(i * i < num)
    {
        if(num % i == 0)
            sum += i + num / i;
            
        i++;
    }
    if(i * i == num)
        sum += i;
    
    if(sum == num * 2)
        return true;
    else
        return false;
}
```

## Analysis

　　这个题目是判断完美数，即所有因数（不含自身）之和等于本身的数，思路比较简单，使用简单暴力的遍历即可，但有几个小坑要注意。

* 坑1：算法超时，虽然是暴力解法，但如果是一个因数一个因数判断，循环终止条件是到 `num/2` 就会出现超时，因此需要将算法的循环终止条件选为 `i*i<num` ，这样每次计算和时还可一次循环加上两个因数。
* 坑2：采用上述循环计算时，有两对因数乘积需要注意。一是恰好 `i*i=num` ，这时要注意这个 `i`  只加一次。二是对于 `1*num=num` 要注意不要多加上了一个num！

