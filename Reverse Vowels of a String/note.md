#345. Reverse Vowels of a String

##Accepted Code

**C:**

	typedef struct Node{
	    char c;
	    struct Node *next;
	}Node;
	
	char* reverseVowels(char* s) {
	    Node *head = NULL, *temp;
	    char c;
	    int i = 0;
	    
	    if(s == NULL)
	        return NULL;
	    
	    c = s[0];
	    while(c != '\0')
	    {
	        if(c=='a' || c=='e' || c=='u' || c=='i' || c=='o' ||
	            c=='A' || c=='E' || c=='U' || c=='I' || c=='O')
	        {
	            temp = malloc(sizeof(Node));
	            temp->c = c;
	            temp->next = head;
	            head = temp;
	            s[i] = '\0';
	        }
	        c = s[++i];
	    }
	    
	    if(head == NULL)
	        return s;
	    
	    c = s[0];
	    i = 0;
	    while(temp != NULL)
	    {
	        if(c=='\0')
	        {
	            s[i] = temp -> c;
	            temp = temp -> next;
	        }
	        c = s[++i];
	    }
	    
	    return s;
	}

##Analysis

　　想了很久啊这个题，没有很通的想到什么简洁的解决方法，最后还是强行用一个笨方法解的，时间效率也不算高，代码还比较长，还得加油啊  
　　o(` · ~ · ′。)o