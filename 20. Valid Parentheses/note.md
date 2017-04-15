# 20.Valid Parenthes

## Accepted Code

**C:**

```c
bool isValid(char* s) {
    char stack[5000];
    int top = 0;
    char c;
    int i = 1;
    stack[0] = '1';
    
    c = s[0];
    while(c != '\0')
    {
        switch(c)
        {
            case '(':
            case '[':
            case '{':
                stack[++top] = c;
                break;
            case ')':
                if(stack[top] == '(')
                    top--;
                else
                    stack[++top] = c;
                break;
            case ']':
                if(stack[top] == '[')
                    top--;
                else
                    stack[++top] = c;
                break;
            case '}':
                if(stack[top] == '{')
                    top--;
                else
                    stack[++top] = c;
                break;
            default:break;
        }
        c = s[i++];
    }
    if(stack[top] == '1')
        return true;
    else
        return false;
}
```

## Analysis

　　这个题目是检查大中小括号的左右对应是否合法，使用栈即可简单解决。