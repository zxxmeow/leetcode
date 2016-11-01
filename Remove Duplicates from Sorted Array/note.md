#26. Remove Duplicates from Sorted Array

>Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

>Do not allocate extra space for another array, you must do this in place with constant memory.

>For example,
Given input array nums = [1,1,2],

>Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

##Accepted Code

**C:**

	int removeDuplicates(int* nums, int numsSize) {
	    int i, k = 0;
	    
	    if(numsSize == 0)
	        return 0;
	    
	    k = 1;
	    for(i = 1; i < numsSize; i++)
	    {
	        if(nums[i] != nums[i - 1])
	            nums[k++] = nums[i];
	    }
	    
	    return k;
	}

##Analysis

　　看到这个题就想到之前那个移除0元素的题，待我找一下~~  
　　好吧就是这个题： `283. Move Zeroes`  
　　这两个题好相似啊，解法也差不多，因为已经是排好序的数组，直接遍历插入，将后面的非重复元素移到前面合适的位置即可，非常简单~~