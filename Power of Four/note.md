#342. Power of Four

##Accepted Code

**C:**

	bool isPowerOfFour(int num) {
	    int temp, length, i;
	    
	    length = sizeof(int) * 4;
	    for(i = 0; i < length; i++)
	    {
	        temp = num & 3;
	        if(num == 1)
	            return true;
	        else if(temp != 0)
	            return false;
	        else
	            num >>= 2;
	    }
	    
	    return false;
	}

##Analysis

　　此题参考 `231. Power of Two` 即可，使用的方法是二进制计算，需要注意的是 ***length = sizeof(int) * 4*** ,一是使用sizeof(int)确保在不同机器上获取到正确的int类型字节数，二是此处使用乘4是因为每次右移位数为2。