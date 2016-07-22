#104. Maximum Depth of Binary Tree

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
	int maxDepth(struct TreeNode* root) {
	    int depth = 0;
	    int l,r;
	    
	    if(root == NULL)
	        return depth;
	    else
	    {
	        l = maxDepth(root->left);
	        r = maxDepth(root->right);
	        return  l > r ? l + 1 : r + 1;
	    }
	}

##Analysis

　　关于求二叉树的最大深度，我使用的是递归算法，代码超级简单哦，但是感觉时间上可能不一定是最优？  
　　看到这道题的时候总是想到树的层序遍历和动态规划，然而并没想清楚有什么联系，也许能再加快一点速度优化一下复杂度什么的？大概吧。。。（当然有可能也不行╮(￣▽￣")╭ ，其实尝试用了一下层序遍历，写到一般发现代码相比上面这个实在是复杂太多了啊。。。长不补短的感觉，于是就放弃了，西西