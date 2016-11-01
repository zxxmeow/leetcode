#448. Find All Numbers Disappeared in an Array

>Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

>Find all the elements of [1, n] inclusive that do not appear in this array.

>Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

##Accepted Code

**C:**

	/**
	 * Return an array of size *returnSize.
	 * Note: The returned array must be malloced, assume caller calls free().
	 */
	int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	    int *result, i,k = 0;
	    
	    *returnSize = 0;
	    result = malloc(sizeof(int) * numsSize);
	    for(i = 0; i < numsSize; i++)
	    {
	        result[i] = 0;
	    }
	    
	    for(i = 0; i < numsSize; i++)
	    {
	        result[nums[i] - 1] = 1;
	    }
	    
	    for(i = 0; i < numsSize; i++)
	    {
	        if(result[i] == 0)
	        {
	            (*returnSize)++;
	            result[k++] = i + 1;
	        }
	    }
	    
	    return result;
	}

##Analysis

　　这道题主要用到的应该是基数排序思想，将数值转化为数组的下标。用此方法还比较简单。  
　　值得思考的是，题目中 *do it without extra space* 的要求，即不使用额外空间的要求，虽然本题只是在返回数组 `result` 中进行操作，但给 `result` 分配的空间大于实际需要返回的数组大小，可以考虑是否还能节省这部分空间。