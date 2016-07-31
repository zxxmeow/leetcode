#13. Roman to Integer

##Accepted Code

**C:**

	int romanToInt(char* s) {
	    char c,pre;
	    int i = 0;
	    int num;
	    
	    pre = '0';
	    c = s[i];
	    while(c != '\0')
	    {
	        switch (c)
	        {
	            case 'M':
	                if(pre == 'C')
	                    num += 900;
	                else
	                    num += 1000;
	                pre = '0';
	                break;
	            case 'D':
	                if(pre == 'C')
	                    num += 400;
	                else
	                    num += 500;
	                pre = '0';
	                break;
	            case 'C':
	                if(pre == 'C')
	                {
	                    num += 200;
	                    pre = '0';
	                }
	                else if(pre == 'X')
	                {
	                    num += 90;
	                    pre = '0';
	                }
	                else
	                    pre = 'C';
	                break;
	            case 'L':
	                if(pre == 'C')
	                {
	                    num += 150;
	                    pre = '0';
	                }
	                else if(pre == 'X')
	                {
	                    num += 40;
	                    pre = '0';
	                }
	                else
	                    num += 50;
	                break;
	            case 'X':
	                if(pre == 'C')
	                {
	                    num += 100;
	                    pre = 'X';
	                }
	                else if(pre == 'X')
	                {
	                    num += 20;
	                    pre = '0';
	                }
	                else if(pre == 'I')
	                {
	                    num += 9;
	                    pre = '0';
	                }
	                else
	                    pre = 'X';
	                break;
	            case 'V':
	                if(pre == 'C')
	                {
	                    num += 105;
	                    pre = '0';
	                }
	                else if(pre == 'X')
	                {
	                    num += 15;
	                    pre = '0';
	                }
	                else if(pre == 'I')
	                {
	                    num += 4;
	                    pre = '0';
	                }
	                else
	                    num += 5;
	                break;
	            case 'I':
	                if(pre == 'C')
	                {
	                    num += 100;
	                    pre = 'I';
	                }
	                else if(pre == 'X')
	                {
	                    num += 10;
	                    pre = 'I';
	                }
	                else if(pre == 'I')
	                {
	                    num += 2;
	                    pre = '0';
	                }
	                else
	                    pre = 'I';
	                break;
	        }
	        c = s[++i];
	    }
	    if(pre == 'C')
	        num += 100;
	    else if(pre == 'X')
	        num += 10;
	    else if(pre == 'I')
	        num += 1;
	    
	    return num;
	}

##Analysis

　　这个题真的是做得我头晕啊头晕！@_@  
　　罗马字母转数字，首先除了一到十几之外别的罗马数字我还不懂。。。所以先查资料吧，由于题目限制了数字在1~3999之间，大概举几个例子如下吧：

>个位数：  
>【I, 1】【II, 2】【III, 3】【IV, 4】【V, 5】【VI, 6】 【VII, 7】【 VIII,8】【IX, 9】
>
>十位数：  
>【X, 10】【XI, 11】【XII, 12】【XIII, 13】【XIV, 14】【XV, 15】【XVI, 16】【XVII, 17】【XVIII, 18】 【XIX, 19】 【XX, 20】【XXI, 21】【XXII, 22】【XXIX, 29】【XXX, 30】【XXXIV, 34】【XXXV, 35】【XXXIX, 39】【XL, 40】【L, 50 】【LI, 51】 【LV, 55】 【LX, 60】 【LXV, 65】 【LXXX, 80】 【XC, 90 】【XCIII, 93】【 XCV, 95 】【XCVIII, 98】【 XCIX, 99 】
>
>百位数：  
【C, 100】 【CC, 200 】【CCC, 300 】【CD, 400】【D, 500 】【DC,600 】【DCC, 700】 【DCCC, 800 】【CM, 900】 【CMXCIX,999】

>千位数：  
【M, 1000】 【MC, 1100 】【MCD, 1400 】【MD, 1500 】【MDC, 1600 】【MDCLXVI, 1666】【 MDCCCLXXXVIII, 1888 】【MDCCCXCIX, 1899 】【MCM, 1900 】【MCMLXXVI, 1976】 【MCMLXXXIV, 1984】 【MCMXC, 1990 】【MM, 2000 】【MMMCMXCIX, 3999】

　　知道大概罗马字母到数字怎样转换后，就是开始观察规律了。首先，用到的罗马字母为 `I` , `V` , `X` , `L` , `C` , `D` , `M` 。对于给的字符串，我们肯定是逐个取字符进行分析计算，而罗马数字表示中，除了普通的字母本身直接代表的数值外，有一类是两个字符需要放在一起考虑，值为右边字母减去左边字母的值，如 `XL` ， `CM` 等，因此只要将这类特殊情况单独考虑即可。  
　　然后就是在画板上涂涂画画的时间了╮(￣▽￣")╭ 分析了一下各个字母特殊情况下前面可以接的字母，结果如下：  
　　M，D---前面为 C 时为特殊情况  
　　L，C---前面为 X 时为特殊情况  
　　V，X---前面为 I 时为特殊情况  
　　另外注意上面这些特殊情况下前面的出现字母只有出现一次有效，即不会出现如 `IIX` 表示 `8` 这种情况。  
　　这样，我只需要当出现 `I` , `X` , `C` 时记录一下，当其后接的字符构成特殊情况时特殊考虑即可。否则按正常的值加上即可。在代码中，使用 `pre` 来记录这样的字母。当其为 `0` 时，表示前面的字母全部结算完毕，否则，表示前一个有对应的字母还未结算。

　　PS：这样计算的时间看了一下记录是第二快的，还有一种更快的算法不造是怎样的呢~~