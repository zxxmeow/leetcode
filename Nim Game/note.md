#292.Nim Game

##Accepted Code

**C:**

	bool canWinNim(int n) {
    if ((n % 4) != 0)
        return true;
    else
        return false;
	}

##Analysis

　　介个题真的好简单啊(￣▽￣")  
　　取物游戏要获胜，一般思考方式就是每次抓取时，使得你抓取的数目与对方前一次抓的数目之和为一个固定的数 ***n*** ，这样每次一轮抓取的数目都是 ***n*** 的倍数。此时只需要根据取物的总数对 ***n*** 的余数，再结合实际的游戏规则即可分析输赢。  
　　这个固定值 ***n*** 的取值，一般当为取数范围为连续时，如本题的1、2、3，则取最大值与最小值之和 `1 + 3 = 4` 。若当取数范围离散时，则尽量使得对放取任何数时，都能在固定回合内保证取数之和的固定，否则需要更进一步的分析。