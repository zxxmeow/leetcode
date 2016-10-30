#118. Pascal's Triangle

##Accepted code

**C：**

	/**
	 * Return an array of arrays.
	 * The sizes of the arrays are returned as *columnSizes array.
	 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
	 */
	int** generate(int numRows, int** columnSizes) {
	    int **result = NULL;
	    int i, j;
	    
	    if(numRows == 0)
	        return result;
	        
	    result = malloc(sizeof(int *) * numRows);
	    *columnSizes = malloc(sizeof(int) * numRows);
	    
	    (*columnSizes)[0] = 1;
	    result[0] = malloc(sizeof(int));
	    result[0][0] = 1;
	    for(i = 1; i < numRows; i++)
	    {
	        (*columnSizes)[i] = i + 1;
	        result[i] = malloc(sizeof(int) * (i + 1));
	        result[i][0] = 1;
	        result[i][i] = 1;
	        for(j = 1; j < i; j++)
	        {
	            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
	        }
	    }
	    
	    return result;
	}

##Analysis

　　发现自己对于C的指针还是有点懵，开始代码如下：

	int** generate(int numRows, int** columnSizes) {
	    int **result = NULL;
	    int i, j;
	    
	    if(numRows == 0)
	        return result;
	        
	    result = malloc(sizeof(int *) * numRows);
	    columnSizes = malloc(sizeof(int *) * numRows);
	    
	    columnSizes[0] = malloc(sizeof(int));
	    columnSizes[0][0] = 1;
	    result[0] = malloc(sizeof(int));
	    result[0][0] = 1;
	    for(i = 1; i < numRows; i++)
	    {
	        columnSizes[i] = malloc(sizeof(int));
	        *columnSizes[i] = i + 1;
	        result[i] = malloc(sizeof(int) * *columnSizes[i]);
	        result[i][0] = 1;
	        result[i][i] = 1;
	        for(j = 1; j < i; j++)
	        {
	            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
	        }
	    }
	    
	    return result;
	}

　　可以看到主要问题就出在 `columnSizes` 上，开始我还很困惑为什么要用二维数组来表示。写完之后一直不对，使用 `1` 进行调试发现当跳出函数时， `columnSizes[0][0]` 的值就变了！百度了以下发现 `columnSizes` 并不是二维数组，而是为了保证分配空间能够使用。

>####C语言中无法把指针变量本身传递给一个函数
>例子：
>
	void GetMemory（char * p, int num）
	{
	   p = (char *)malloc(num*sizeof(char));
	}
	intmain()
	{
	   char *str = NULL;
	   GetMemory（str，10）;
	   strcpy(str,”hello”);
	   free（str）；//free 并没有起作用，内存泄漏
	   return 0;
	}

>在运行strcpy(str,”hello”)语句的时候发生错误。这时候观察str 的值，发现仍然为NULL。也就是说str 本身并没有改变，我们malloc 的内存的地址并没有赋给str，而是赋给了_str(函数中的str，即P）。

>而这个_str 是编译器自动分配和回收的，我们根本就无法使用。所以想这样获取一块内存是不行的。那怎么办? 两个办法：

>* 第一：用return。
>
		char * GetMemory（char * p, int num）
		{
		   p = (char *)malloc(num*sizeof(char));
		   return p；
		}
		intmain()
		{
		   char *str = NULL;
		   str = GetMemory（str，10）;
		   strcpy(str,”hello”);
		   free（str）；
		   return 0;
		}

>* 第二：用二级指针。
>
		void GetMemory（char ** p, int num）
		{
		   *p = (char *)malloc(num*sizeof(char));
		   return p；
		}
		intmain()
		{
		   char *str = NULL;
		   GetMemory（&str，10）;
		   strcpy(str,”hello”);
		   free（str）；
		   return 0;
		}

>注意，这里的参数是 `&str` 而非 `str` 。这样的话传递过去的是str 的地址，是一个值。在函数内部，用钥匙 `*` 来开锁： `*(&str)` 其值就是str。所以malloc分配的内存地址是真正赋值给了str 本身。