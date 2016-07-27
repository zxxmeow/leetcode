#171. Excel Sheet Column Number

##Accepted Code

**C:**

	int titleToNumber(char* s) {
	    int num=0, i=0;
	    char c;
	    
	    c = s[i];
	    while(c != '\0')
	    {
	        num = (num * 26) + (c - 'A' + 1);
	        c = s[++i];
	    }
	    
	    return num;
	}

##Analysis

　　这个题也很简单啦，就一个26进制而已。。。。