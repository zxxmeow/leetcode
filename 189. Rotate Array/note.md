# 189. Rotate Array

## Accepted Code

**C:**

```c
void rotate(int* nums, int numsSize, int k) {
    int i, j;
    int n, m;
    int temp;
    
    if(k > 0 && numsSize != k)
    {
        i = numsSize - (k % numsSize);
        n = i;
        while(i < numsSize)
        {
            temp = nums[i];
            j = i;
            for(m = 0; m < n; m++)
            {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = temp;
            i++;
        }
    }
}
```

## Analysis

题看了半天才看懂。。。。好吧就是数组循环右移k位（要注意k可能大于数组大小）目前的解法思路比较~~简单~~暴力，不过解法思路很多，肯定是有更简单的方法的！
