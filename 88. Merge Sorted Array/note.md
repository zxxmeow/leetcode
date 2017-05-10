# 88. Merge Sorted Array

## Accepted Code

**C:**

```c
void merge(int* nums1, int m, int* nums2, int n) {
    int i,j,k;
    
    i = m - 1;
    j = n - 1;
    k = m + n - 1;
    
    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    if(i < 0)
        for( ; k >= 0; k--)
            nums1[k] = nums2[j--];
}
```

## Analysis

　　合并两个有序数组，将nums2放到nums1里，非常简单！注意从后往前插入数组可以免去移动数组元素的花销。



