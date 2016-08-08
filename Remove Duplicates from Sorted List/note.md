#83. Remove Duplicates from Sorted List

##Accepted Code

**C:**

	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     struct ListNode *next;
	 * };
	 */
	struct ListNode* deleteDuplicates(struct ListNode* head) {
	    struct ListNode *pre, *current;
	    if(head == NULL)
	        return head;
	    
	    pre = head;
	    current = head -> next;
	    
	    while(current != NULL)
	    {
	        if(pre -> val == current -> val)
	        {
	            //free(pre -> next);
	            pre -> next = NULL;
	        }
	        else
	        {
	            pre -> next = current;
	            pre = current;
	        }
	        current = current -> next;
	    }
	    
	    return head;
	}

##Analysis

　　嗯，又是一个链表基础操作题，删除链表里的重复元素，太简单了，并没有什么好分析的啦~