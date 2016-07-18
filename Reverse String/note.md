#332.Reverse String

##Accept code

**C：**

	char* reverseString(char* s) {
	    char * result;
	    int i = 0, j;
	    
	    while(s[i] != '\0'){i++;}
	    
	    result = malloc(sizeof(char) * (i+1));
	    result[i] = '\0';
	    for(j = 0; j < i; j++)
	    {
	        result[i-j-1] = s[j];
	    }
	    
	    return result;
	}

##problem

* 原始代码中，内存分配为 `result = malloc(sizeof(char) * i)` 并且没有 `result[i] = '\0'` ，即分配i个char型内存，字符串 `result` 中只存储字符串内容，不存储 `'\0'`，错误提示为：

		input:		"race car"
		output:		"rac ecar...."
		Expected:	"rac ecar"
使用该例调试后发现，给 `result` 分配内存后，此时查看 `result` 的值并不是8个char的长度。 `result` 拥有超过字符串的长度。之后我通过添加 `'\0'` 完成了修改。  
但为了弄清使用 `malloc()` 分配时到底会分配多少空间，我又尝试修改 `i` 的值进行调试，发现分配的大小确实会超出 `char * i` 的大小。

* 同上一点，在修改 `i` 值进行调试时，发现在调试时和运行时得到的结果不相同。（这让我想起大一时某个程序运行时一切正常，但在调试时总是会在末尾输出奇怪的符号，比如笑脸☺之类的，当时也并没有解决。。。）  
注：本地调试使用的是 `Dev-C++` 。

* 当我加上 `'\0'` ，并将内存分配为 `char * i` 时，出现以下错误：

		Last executed input:	"Trap a rat! Stare
								piper
								at Star apart."