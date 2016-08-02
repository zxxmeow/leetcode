#231. Power of Two

##Accepted Code

**C:**

二进制位计算：

	bool isPowerOfTwo(int n) {
	    int i, length, temp;
	    
	    length = sizeof(int) * 8;
	    for(i = 0; i < length; i++)
	    {
	        temp = n & 1;
	        if(temp == 1)
	            if(n == 1)
	                return true;
	            else
	                return false;
	                
	        n >>= 1;
	    }
	    
	    return false;
	}

直接计算：

	bool isPowerOfTwo(int n) {
	    double num;
	    num = n;
	    
	    while(num >= 1)
	    {
	        if(num == 1)
	            return true;
	        
	        num /= 2;
	    }
	    
	    return false;
	}

##Analysis

　　做这个问题前刚好瞄到了一下二进制计算，发现好像是很好用呢。然后考虑了一下写出了第一种算法。但还是写一下普通算法吧，如上第二种。看了一下Submission Details，发现时间上两种算法好像并没有什么区别，嘛~就酱吧o_O  
　　算法还是比较容易的，主要讲下遇到的问题（心酸泪史）吧（哭  
　　第一种二进制算法开始还有点没想清楚，只知道二的次幂是 `0…010…0` 型的，也就是只有二进制中一个位是1，开始想的是直接右移，如果某次结果为1则返回true，然而果然脑抽没有想到右移出去的不管1还是0都没有了= = 所以改成了判断最后右移出去的一位是0还是1。另外还有一个问题简直困扰了特别久，眼瞎一直没发现，怎么都觉得是对的，最后祭出大杀器，那本地编译器调试了一下，立马就发现。。。开始的时候写的是 `length = sizeof(int);` ，这样鬼才对啊！（好吧，1，2，4这种小数还是对的）要乘以8啊亲！  
　　第二种方法的话，主要就是精度的问题了，第一次我用的是 `float`，会得到 `Wrong Answer` ，果然改成 `double` 型就AC了~