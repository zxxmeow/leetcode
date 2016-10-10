#141. Linked List Cycle

##Accepted Code

**C:**

	/**
	 * Definition for singly-linked list.
	 * struct ListNode {
	 *     int val;
	 *     struct ListNode *next;
	 * };
	 */
	bool hasCycle(struct ListNode *head) {
	    struct ListNode *fast, *slow;
	    fast = head;
	    slow = head;
	    
	    while(fast != NULL)
	    {
	        fast = fast -> next;
	        if(fast == NULL)
	            break;
	        fast = fast -> next;
	        slow = slow -> next;
	        if(fast == slow)
	            return true;
	    }
	    
	    return false;
	}

##Analysis

　　这道题解法还是很巧妙的，只能靠灵感了╮(￣▽￣")╭  
　　大致解法用到的就是数学上的追赶问题，使用两个指针，一个快的每次走两个节点，慢的每次走一个节点，如果最终能相遇，则说明链表有环咯。  
　　（开始还想每经过一个节点就删除一个节点，如果到某个 `next` 非NULL的节点访问下一节点出错时则说明有环，但并不知道怎么截取访问报错。。。