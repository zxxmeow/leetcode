#24. Swap Nodes in Pairs

##Accepted Code

**C:**

	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     struct ListNode *next;
	 * };
	 */
	struct ListNode* swapPairs(struct ListNode* head) {
	    struct ListNode *pre, *current, *end;
	    
	    if(head == NULL)
	        return head;
	    
	    pre = head;
	    current = head -> next;
	    if(current == NULL)
	        return head;
	    else
	    {
	        head = current;
	        pre -> next = current -> next;
	        current ->next = pre;
	        end = pre;
	        pre = end -> next;
	        while(pre != NULL)
	        {
	            current = pre -> next;
	            if(current == NULL)
	                return head;
	            else
	            {
	                end -> next = current;
	                pre -> next = current -> next;
	                current -> next = pre;
	                end = pre;
	                pre = end -> next;
	            }
	        }
	        
	        return head;
	    }
	    
	}

##Analysis

　　**重要提示：**  
　　如果做不出来或者思路混乱的时候，用笔在纸上写写画画很！有！用！