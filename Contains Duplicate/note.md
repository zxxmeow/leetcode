#217. Contains Duplicate

##Accepted Code

**C:**

	bool containsDuplicate(int* nums, int numsSize) {
	    int i, j, temp;
	    
	    for(i = 1; i < numsSize; i++)
	    {
	        temp = nums[i];
	        for(j = i - 1; j >= 0; j--)
	        {
	            if(temp < nums[j])
	                nums[j + 1] = nums[j];
	            else if(temp == nums[j])
	                return true;
	            else
	            {
	                nums[j + 1] = temp;
	                break;
	            }
	        }
	    }
	    return false;
	}

##Analysis

　　（发现easy难度排序下来的题有的超简单，有的又好麻烦啊。。。。不科学= =。。。  
　　这个题是查找数组里是否有重复元素，想法还是比较简单的，就是将数组排序一下即可。我采用的是插入排序，由于在排序过程中需要逐个比较，因此发现重复元素时直接返回 `true` ，可以稍微更方便一些。如果整个排序过程完成也没有返回 `true` ，说明没有相同元素，此时返回 `false` 即可。  
　　另外，插入排序这种基础的东西我居然都没有记清！脑抽了吧大概。。。。写的第一版代码中，没有使用 `temp` 变量，而是直接使用 `nums[i]` 进行比较，这是一个很傻的错误。。。。因为 `nums[i]` 在产生向后移位时，值就改变了呀！好好记住呀！