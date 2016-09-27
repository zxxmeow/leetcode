#198. House Robber

##Accepted Code

**C:**

	int rob(int* nums, int numsSize) {
	    int temp[3] = {0};
	    int max = 0, i;
	    
	    if(numsSize == 1)
	        return nums[0];
	    else if(numsSize == 2)
	        return nums[0] > nums[1] ? nums[0] : nums[1];
	    else if(numsSize == 3)
	    {
	        if(nums[0] + nums[2] > nums[1])
	            return nums[0] + nums[2];
	        else
	            return nums[1];
	    }
	    else
	    {
	        temp[0] = nums[0];
	        temp[1] = nums[1];
	        temp[2] = nums[0] + nums[2] > nums[1] ? nums[0] + nums[2] : nums[1];
	        for(i = 3; i < numsSize; i++)
	        {
	            if(temp[(i - 1) % 3] > temp[(i - 3) % 3] + nums[i])
	                temp[i % 3] = temp[(i - 1) % 3];
	            else
	                temp[i % 3] = temp[(i - 3) % 3] + nums[i];
	            
	            if(temp[i % 3] < temp[(i - 2) % 3] + nums[i])
	                temp[i % 3] = temp[(i - 2) % 3] + nums[i];
	        }
	    }
	    
	    if(temp[0] > temp[1])
	        max = temp[0];
	    else
	        max = temp[1];
	    
	    if(max > temp[2])
	        return max;
	    else
	        return temp[2];
	}

##Analysis

　　这道题主要就是用到动态规划的思想了，将问题分解为小问题。对于街道上的 `n` 个房子，假设第 `n` 个房子的钱为 `Xn` ，若一定偷取第 `n` 个房子的情况下最大能偷取的金额为 `f(n)` ，则 `f(n)` 一定为 `f(n-1) : f(n-2)+Xn : f(n-3)+Xn` 中的最大值。使用一个三元组 `temp[3]` 来存储最大可偷取的钱数（temp[n%3]），随着n的增大，根据规则计算更新temp数组即可。