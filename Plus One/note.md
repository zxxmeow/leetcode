#66. Plus One

##Accepted code

**C：**

	/**
	 * Return an array of size *returnSize.
	 * Note: The returned array must be malloced, assume caller calls free().
	 */
	int* plusOne(int* digits, int digitsSize, int* returnSize) {
	    int i , c = 0;
	    int *result = NULL;
	    *returnSize = digitsSize + 1;
	    result = malloc(sizeof(int) * *returnSize);
	    
	    if((result[*returnSize - 1] = digits[digitsSize - 1] + 1) == 10)
	    {
	        result[*returnSize - 1] = 0;
	        c = 1;
	    }
	    
	    for(i = 2; i <= digitsSize; i++)
	    {
	        if(c == 1)
	        {
	            if((result[*returnSize - i] = digits[digitsSize - i] + 1) == 10)
	            {
	                result[*returnSize - i] = 0;
	            }
	            else
	                c = 0;
	        }
	        else
	            result[*returnSize - i] = digits[digitsSize - i];
	    }
	    
	    if(c == 1)
	        result[0] = 1;
	    else
	    {
	        result = result + 1;
	        *returnSize = *returnSize - 1;
	    }
	    
	    return result;
	}

##Analysis
　　这个题太坑了！  
　　之前一直以为形参里的 *`int* returnSize`* 是给定的，结果一直得不到结果，还以为是没有分配空间，检查了明明有malloc，然后自己开dev调试，结果都是对的！没想到居然是 *`returnSize`* 居然是要自己赋值！  
　　发现这个问题之后就好解决多了╮(╯-╰)╭，然后这个题比较需要注意的就是 **进位** 啦