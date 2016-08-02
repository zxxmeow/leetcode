#include<stdio.h>

int isPowerOfTwo(int n) {
    int i, length, temp;
    
    length = sizeof(int) * 8;
    for(i = 0; i < length; i++)
    {
        temp = n & 1;
        if(temp == 1)
            if(n == 1)
                return 1;
            else
                return 0;
                
        n >>= 1;
    }
    
    return 0;
}

main() {
    int n;
    
    scanf("%d", &n);
    printf("%d", isPowerOfTwo(n));
    
    system("pause");
    return 0;
}
