# 125. Valid Palindrome

## Accepted Code

**C:**

```c
bool isPalindrome(char* s) {
    int i, j;
    
    j = strlen(s) - 1;
    i = 0;
    
    while(i < j)
    {   
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(s[j] >= 'A' && s[j] <= 'Z')
            {
                if(s[i] != s[j])
                    return false;
                i++;
                j--;
            }
            else if(s[j] >= 'a' && s[j] <= 'z')
            {
                if((s[i] + 32) != s[j])
                    return false;
                i++;
                j--;
            }
            else if(s[j] >= '0' && s[j] <= '9')
                return false;
            else
                j--;
        }
        else if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(s[j] >= 'A' && s[j] <= 'Z')
            {
                if(s[i] != (s[j] + 32))
                    return false;
                i++;
                j--;
            }
            else if(s[j] >= 'a' && s[j] <= 'z')
            {
                if(s[i] != s[j])
                    return false;
                i++;
                j--;
            }
            else if(s[j] >= '0' && s[j] <= '9')
                return false;
            else
                j--;
        }
        else if(s[i] >= '0' && s[i] <= '9')
        {
            if((s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= 'a' && s[j] <= 'z'))
                return false;
            else if(s[j] >= '0' && s[j] <= '9')
            {
                if(s[i] != s[j])
                    return false;
                i++;
                j--;
            }
            else
                j--;
        }
        else
            i++;
    }
    return true;
}
```

## Analysis

这个题。。真的。。。让人写到崩溃，倒不是因为有多难，主要是要考虑的情况太多太杂乱，而题目本身很容易，这就显得这个题更加讨厌了！（怪不得这个题点赞才41，反对的有124辣么多。。。。）本题是要判断回文序列，但其中有扰乱（不计算）的各种标点符号，然后字母大小写不区分，还有数字。主要是在ASCII表里这些符号需要判断的都被隔成一段一段，导致判断条件很多，当我第一次想得很简单，嗖嗖十来行代码写完，然后发现，“哦，不行，大小写居然是不区分的“（要记得表中大小写字母中间的符号是不计算的哦~）。待我好不容易改完大小写，“哦，还有数字又是需要考虑的”。总之此题~~十分繁杂而又无甚意义~~，可以好好锻炼你的思考各类情形的能力，推荐给想要做测试的同学哟~~（总之我已经决定以后这种反对很多的题就直接跳过了。。。）
