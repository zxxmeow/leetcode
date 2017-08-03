# 414. Third Maximum Number

## Accepted Code

**C:**

```c
int thirdMax(int* nums, int numsSize) {
    int max, med, min;
    int i = 0;
    
    max = med = min = 0;
    for(i = 1; i < numsSize; i++)
    {
        if(nums[i] > nums[max])
        {
            min = med;
            med = max;
            max = i;
        }
        else if(nums[i] < nums[max])
        {
            if(max == med)
                med = min = i;
            else if(nums[i] > nums[med])
            {
                min = med;
                med = i;
            }
            else if(nums[i] < nums[med])
            {
                if(min == med)
                    min = i;
                else if(nums[i] > nums[min])
                    min = i;
            }
        }
    }
    
    if(min == med)
        return nums[max];
    else
        return nums[min];
}
```

## Analysis

看起来很简单的题，但其实要考虑的东西还是挺多的，开始主要问题是在判断是否有第三大的数上，后来想想还是比较简单，先都赋值为第一个数，后来再判断第二大和第三大是不是同一个即可。然而想要一次成功还是比较难，总是错过几种情况，想到后来都有点混乱了，感觉可能还是在纸上写一写比较好~