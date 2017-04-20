# 1.Two Sum

## Accepted Code

**C:**

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int hash[10000];
    int *result;
    int i, n;
    
    result = malloc(sizeof(int) * 2);
    for(i = 0; i <= 9999; i++)
        hash[i] = -1;
    
    for(i = 0; i < numsSize; i++)
    {
        n = nums[i];
        if(n <= 5000)
        {
            if(hash[5000 + n] != -1)
            {
                result[0] = hash[5000 + n];
                result[1] = i;
                break;
            }
            else
                hash[5000 + (target - n)] = i;
        }
    }
    
    return result;
}
```

## Analysis

　　终于解决了这个问题！！！去年被这个题虐的情景还历历在目！！！为此还发过长微博吐槽！！！（后来有人指导了我用基数排序的思想= =

​	其实这次看这个题还是挺简单的，就是用到了 `hash table` ，对于 `a+b=target` ，遇到 `a` 时在 `hash[target - a]`  （即 `hash[b]` ）中存下 `a` 的位置即可，这样当遇到 `b` 时，判断 `hash[b]` 中不为初值即可知道答案为 `a，b` 。

* 要注意的是可能有负数，因此以 `hash[5000]` 为零点即可。