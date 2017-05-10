# 58. Length of Last Word

## Accepted Code

**C:**

```c
int lengthOfLastWord(char* s) {
    int num = 0;
    int i = 0;
    bool flag = false;
    char c;
    
    c = s[i++];
    
    while(c != '\0')
    {
        if(c == ' ')
            flag = true;
        else if(flag)
        {
            flag = false;
            num = 1;
        }
        else
            num++;
        
        c = s[i++];
    }
    
    return num;
}
```

## Analysis

　　计算字母字符串中最后一个单词的长度，还是比较简单的，不过有一点需要注意，开始时以为最后一位是空格时应返回0，一直出错还以为是字符数组下标搞错，最后发现是理解问题，最后一位为空格时答案还是最后一个单词的值。。。

​	(╯﹏╰)b



