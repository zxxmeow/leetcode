#100. Same Tree

##Accepted Code

**C:**

	/**
	 * Definition for a binary tree node.
	 * struct TreeNode {
	 *     int val;
	 *     struct TreeNode *left;
	 *     struct TreeNode *right;
	 * };
	 */
	bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	    if(p == NULL || q == NULL)
	    {
	        if(p == q)
	            return true;
	        else
	            return false;
	    }
	    else
	    {
	        if(p->val == q->val)
	            return true & isSameTree(p->left, q->left) & isSameTree(p->right, q->right);
	        else
	            return false;
	    }
	}

##Analysis

　　前面跳过了两个题。。。一个觉得很麻烦不会做。。还有一个感觉题目没懂。。。尴尬。。。  
　　这个题也没什么好说的啦，判断两个树是不是相等，使用了递归，先序遍历树，同时比较 `val` 的值是否相等即可。  
　　但还有一个问题就是这样的时间效率并不是很好，应该有更快速的算法嗯。。。。。