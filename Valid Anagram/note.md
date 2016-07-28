#242. Valid Anagram

##Accepted Code

**C:**

	bool isAnagram(char* s, char* t) {
	    int count[26] = {0};
	    char c;
	    int i = 0;
	    
	    c = s[i];
	    while(c != '\0')
	    {
	        count[c - 'a']++;
	        c = s[++i];
	    }
	    
	    i = 0;
	    c = t[i];
	    while(c != '\0')
	    {
	        count[c - 'a']--;
	        c = t[++i];
	    }
	    
	    for(i=0; i<26; i++)
	    {
	        if(count[i] != 0)
	            return false;
	    }
	    return true;
	}

##Analysis

　　这个题目是判断两个字符串是否为易位构词，即相同字母异序词。题目本身由于字符串限定在小写字母之内，所以还是比较简单，用一个26位数组记录一下每个字符出现次数再进行比较即可。  
　　为了进一步简化代码，节省空间，将原本每个字符串用一个数组计数再比较改为只使用一个数组，初始为0，一个字符串计数时出现一个字符在数组对应位加一，另一个字符串技术时出现一个字符串减一，最后判断数组元素是否都为0即可知道两个字符串是否anagram。这样就节省了一个数组的开销~  
　　但本题还有一个进阶要求：

>　　What if the inputs contain unicode characters? How would you adapt your solution to such case?

　　这样就不能使用固定数组来记录了，我目前的想法是，用一个链表或长数组来存储出现的字符及出现次数，同时根据字符元素码值排序。记录完成后从链表头开始逐一比较，由于是已排序的，这样一出现不符合的情形即可判定不是anagram啦~  
　　暂时还只是一个想法，没有编码实现，但感觉还是比较靠谱的嘛~~嗯，感觉可能还有更好更快速的进阶算法吧。。。大概。。。