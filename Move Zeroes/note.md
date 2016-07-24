#283. Move Zeroes

##Accepted Code

**C:**

	void moveZeroes(int* nums, int numsSize) {
	    int i, j = 0;
	    
	    for(i = 0; i < numsSize; i++)
	    {
	        if(nums[i] != 0)
	            nums[j++] = nums[i];
	    }
	    
	    for(; j < numsSize; j++)
	        nums[j] = 0;
	    
	}

##Analysis

　　这个题也是比较简单的，首先一眼看到题目，就是数组排序的类型，首先想到的就是冒泡排序和插入排序，但冒泡排序在这里不太适用而且效率比较低，插入排序则相对更合适。  
　　然而此题还有额外要求：

>Note:  
>1. You must do this in-place without making a copy of the 
>array.
>2. Minimize the total number of operations.

　　所以很明显需要在换一种方法，由于只能在原数组上操作，又要保证对数组元素的操作数越少越好，机智的我发现，所有的0最终都会在数组末尾，要完成的操作即将后面的 `非0` 向前挪到 `0` 的位置，这样我们对于 `非0` 要插入到 `0` 的位置时就可以不需要考虑位置交换，直接覆盖就行，当完成所有排序后，在数组末尾补上合适个数的 `0` 即可。  
　　（感觉也没有说得很清楚，嘛~就看代码吧，反正很简单~~