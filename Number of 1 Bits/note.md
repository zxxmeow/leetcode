#191. Number of 1 Bits

##Accepted Code

**C:**

	int hammingWeight(uint32_t n) {
	    int num = 0;
	    int count = 32;
	    
	    while(count != 0)
	    {
	        if(n & 1 == 1)
	            num++;
	        
	        n >>= 1;
	        count--;
	    }
	    
	    return num;
	}

##Analysis

　　前几天想那个happy num的问题一直没有想出来。。。今天碰到的这个结果又好简单= =  
　　总之就是二进制计算啦，用了最普通的查看最后一位，右移，循环32次的方式。