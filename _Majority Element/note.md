#169. Majority Element

##Accepted Code

**C:**

	bool canWinNim(int n) {
    if ((n % 4) != 0)
        return true;
    else
        return false;
	}

##problem

　　求数组的 `主要元素` ，开始我想的使用递归的方式，判断最后一个元素与之前数组的 `主要元素` 进行比较。如果假设可以保证一定有且只有结果的话，最后两个元素一样时才有可能超过前面子数组的 `主要元素` 。开始的代码如下：

	int majorityElement(int* nums, int numsSize) {
	    int i, k, m = 0, n = 0;
	    
	    if(numsSize == 1)
	        return nums[0];
	    else
	    {
	        i = majorityElement(nums, numsSize - 1);
	        if(i == nums[numsSize - 1] || nums[numsSize - 1] != nums[numsSize - 2])
	            return i;
	        else
	        {
	            for(k = 0; k < numsSize; k++)
	            {
	                if(nums[k] == i)
	                    m++;
	                if(nums[k] == nums[numsSize - 1])
	                    n++;
	            }
	            return m > n ? i : nums[numsSize - 1];
	        }
	    }
	}

　　但这样无法AC，会出现超时错误：

>Time Limit Exceeded

　　不行啦~( >﹏<。)写不粗来惹，改来改去都改晕了，先暂放一下现在的代码吧，以后再改。。。

	int majorityElement(int* nums, int numsSize) {
	    int i, j, k, m=0, n=0;
	    
	    i = nums[0];
	    for(j = 1; j < numsSize - 1; j++)
	    {
	        if(i != nums[j])
	        {
	            if(m == n ||(m != n && nums[j] == nums[j + 1]))
	            {
	                m = n = 0;
	                for(k = 0; k <= j; k++)
	                {
	                    if(nums[k] == i)
	                        m++;
	                    if(nums[k] == nums[j])
	                        n++;
	                }
	                i = m > n ? i : nums[j];
	                if(m != n)
	                    j = j + 1 > 2 * m - 2 ? j + 1 : 2 * m - 2 ;
	            }
	        }
	    }
	    return i;
	}