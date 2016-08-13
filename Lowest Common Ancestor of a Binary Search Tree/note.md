#235. Lowest Common Ancestor of a Binary Search Tree

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
	struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
	    struct TreeNode *result;
	    
	    result = root;
	    while(result != NULL)
	    {
	        if(p->val == result->val || q->val == result->val)
	            return result;
	        else if(((p->val < result->val) ^ (q->val > result->val)) == false)
	            return result;
	        else if(p->val < result->val)
	        {
	            result = result -> left;
	        }
	        else
	        {
	            result = result ->right;
	        }
	    }
	    
	    return result;
	}

##Analysis

　　有一小撮有更快解决算法的人，好在意是什么啊。。。