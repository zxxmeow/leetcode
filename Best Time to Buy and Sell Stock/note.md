#121. Best Time to Buy and Sell Stock

##Accepted Code

**C:**

	int maxProfit(int* prices, int pricesSize) {
	    int min, profit = 0;
	    int i;
	    
	    min = prices[0];
	    for(i = 1; i < pricesSize; i++)
	    {
	        if(prices[i] < min)
	            min = prices[i];
	        else if(prices[i] - min > profit)
	            profit = prices[i] - min;
	    }
	    
	    return profit;
	}

##Analysis

　　看到这个题第一眼就想到算法课上动态规划时候求最大子序列和问题，（虽然到现在我也没有很明白动态规划是啥╮(￣▽￣")╭）这个题基本也没什么难度，就酱吧~  
　　另外注意到一点是第一次提交，看到运行时间是8ms，看了下是最慢的了啊，不甘心，看了下答案，明显跟我一样的算法嘛！然后又提交一次，4ms，代码明明一样的！都是200个测试！好吧。。。难道是网络问题？