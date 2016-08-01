#206. Reverse Linked List

##Accepted Code

**C:**

	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     struct ListNode *next;
	 * };
	 */
	struct ListNode* reverseList(struct ListNode* head) {
	    struct ListNode *result, *last;
	    
	    last = result = NULL;
	    while(head != NULL)
	    {
	        result = malloc(sizeof(struct ListNode));
	        result = head;
	        head = head -> next;
	        result -> next = last;
	        last = result;
	    }
	    
	    return result;
	}

##Analysis

　　基础题，链表倒序，使用的是头插法，很简单，倒是自己C语言链表、指针相关的有点忘记了，需要复习复习了啊。。。。(￣△￣；)  
　　另外结果中有更快的算法，暂时还没有想到= =