#27. Remove Element

##Accepted Code

**C:**

	int removeElement(int* nums, int numsSize, int val) {
	    int pos = 0;
	    int i;
	    
	    for(i = 0; i < numsSize; i++)
	    {
	        if(nums[i] != val)
	        {
	            nums[pos++] = nums[i];
	        }
	    }
	    
	    return pos;
	}

##Analysis

　　此题为删除重复元素，要求只使用静态变量空间，由于对要删除的元素不要求保留，此题还是非常简单的！（看看代码应该一眼就能看懂吧。。大概。。