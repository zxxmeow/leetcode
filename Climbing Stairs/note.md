#70. Climbing Stairs

##Accepted Code

**C:**

	int climbStairs(int n) {
	    if(n == 0)
	        return 0;
	    else
	        return 1/sqrt(5) * (pow((1 + sqrt(5))/2 , n+1) - pow((1 - sqrt(5))/2 , n+1));
	}

##Analysis

　　爬楼梯问题应该是很经典的智力题了，由于只能一次爬1或2层，爬 `n` 层楼的方法可以有：爬 `n-1` 层楼的后再爬一层，或爬 `n-2` 层楼后再一次爬两层。则总方法数为应为这两种方法数之和，如果用 `a(n)` 来表示爬n层楼的方法数，则很明显有：  
　　**a(n) = a(n-1) + a(n-2)**  
　　很明显这是一个Fibonacci数列  
　　但是！第一次代码为：  

	int climbStairs(int n) {
	    if(n == 0)
	        return 0;
	    else if(n == 1)
	        return 1;
	    else if(n == 2)
	        return 2;
	    else
	        return climbStairs(n - 1) + climbStairs(n - 2);
	}

　　此时会产生超时错误。。。。╮(￣▽￣")╭  
　　那么这种情况我就只好把通项公式算出来咯。然而。。问题是。。。我已经忘了通项公式求解方法！并算不出来！好吧，只能求助百度了，看了一下特征方程求解的方法（然后把公式抄了过来），问题解决~
　　

　　*注：公式里用的 `n+1` 而不是 `n` 主要是因为此题数列项a1、a2是从1，2开始的*