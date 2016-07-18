#include<stdio.h>

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

main() {
    char *s;
    s = malloc(sizeof(char)*100);
    
    gets(s);
    puts(reverseString(s));
    
    system("pause");
    return 0;
}

