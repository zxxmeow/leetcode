#263. Ugly Number

##Accepted Code

**C:**

	bool isUgly(int num) {
	    if(num == 0)
	        return false;
	    
	    while(num != 1)
	    {
	        if(num % 5 == 0)
	            num = num / 5;
	        else if(num % 3 == 0)
	            num = num / 3;
	        else if(num % 2 == 0)
	            num = num / 2;
	        else
	            return false;
	    }
	    
	    return true;
	}

##Analysis

　　这个题目前只想到了用while循环相除进行判断，还是比较简单的。  
　　另外要注意的是，第一次提交时，三重的 `if-else` 判断是以 `2 3 5` 的判断顺序，测试用时7ms。之后改成了 `5 3 2` 的顺序，时间则提高到了4ms。总之就是虽然看起来差不多，但顺序什么的改变一小点也是会对运行时间造成影响的哟~