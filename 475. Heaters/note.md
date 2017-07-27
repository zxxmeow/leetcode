# 475. Heaters

## Accepted Code

**C:**

```c
/*void sort(int *array, int len)
{
    int i, j;
    int min;
    int temp;
    
    for(i = 0; i < len - 1; i++)
    {
        min = i;
        for(j = i + 1; j < len; j++)
        {
            if(array[j] < array[min])
                min = j;
        }
        if(min != i)
        {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}*/

void sort(int *a, int left, int right)
{
    int i = left;
    int j = right;
    int key = a[left];
    
    if(left >= right)
    {
        return ;
    }
    
    while(i < j)
    {
        while(i < j && key <= a[j])
            j--;
         
        a[i] = a[j];
         
        while(i < j && key >= a[i])
            i++;
         
        a[j] = a[i];
    }
    a[i] = key;
    sort(a, left, i - 1);
    sort(a, i + 1, right);
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    int max = 0;
    int i = 0, j = 0;
    
    sort(houses, 0, housesSize - 1);
    sort(heaters, 0, heatersSize - 1);
    
    if(houses[i] < heaters[j])
        max = heaters[j] - houses[i];
    
    while(i < housesSize)
    {
        if(houses[i] >= heaters[j])
        {
            while(j < heatersSize - 1 && houses[i] > heaters[j + 1])
                j++;
            
            if(j == heatersSize - 1)
            {
                if((houses[housesSize - 1] - heaters[j]) > max)
                    max = houses[housesSize - 1] - heaters[j];
                
                break;
            }
                    
            if((heaters[j + 1] - heaters[j]) > (2 * max))
                if(2 * (houses[i] - heaters[j]) < (heaters[j + 1] - heaters[j]) && (houses[i] - heaters[j]) > max)
                    max = houses[i] - heaters[j];
                else if(2 * (heaters[j + 1] - houses[i]) < (heaters[j + 1] - heaters[j]) && (heaters[j + 1] - houses[i]) > max)
                    max = heaters[j + 1] - houses[i];
        }
        i++;
    }
    
    return max;
}
```

## Analysis

啊啊啊这个题想了我好久啊！

基础思路是找到在所有房子到加热器的最短距离里找到最大值即可。用 `max` 来存储这个值，用 `i` 表示房子的位置，`j` 表示加热器的位置。考虑 `i` 在 `j` 和 `j+1` 之间；第一个 `i` 小于所有的 `j` ；最后一个 `i` 大于所有的 `j` 三种情况。编好后发现，它的数组居然不是排好序的！！！这时候因为懒得排序，想到能不能用动态规划来做，先固定所有加热器，然后问题就能划分为求前 `i-1` 个房子的解和求第 `i` 个房子到最近加热器的距离，这两者中较大的值即为问题的解~

然而发现这样还是绕不过排序。。。。所以就还是继续按此方法加上了排序，先用了选择排序，然后超时。。。然后改成快速排序，没注意函数的参数和数据下标的关系，报了一个错

> free(): invalid next size (fast): 0x0000000001c6c340 ***

搜了一下是内存泄漏问题，可能是数组越界使用和new/delete或malloc/free不匹配的问题。

最终虽然AC，但是时间效率不是很高，不知道用动态规划会不会快一点。。。或者还有什么别的更快速的方法（要是不需要排序就好了，讨厌排序>…<