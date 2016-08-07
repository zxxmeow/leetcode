#326. Power of Three

##Accepted Code

**C:**

	bool isPowerOfTwo(int n) {
	    double num;
	    num = n;
	    
	    while(num >= 1)
	    {
	        if(num == 1)
	            return true;
	        
	        num /= 3;
	    }
	    
	    return false;
	}

##Analysis

　　这个题想了很久还是没想到怎么使用非循环的算法，还是用的类似 `Power of Two` 里的普通算法，果然看了结果还是很耗时啊。。。（另外看了一眼，Java的时间居然快了很多诶好神奇~