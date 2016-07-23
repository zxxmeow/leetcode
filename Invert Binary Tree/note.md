#226. Invert Binary Tree

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
	struct TreeNode* invertTree(struct TreeNode* root) {
	    struct TreeNode *temp;
	    
	    if(root == NULL)
	        return NULL;
	    else
	    {
	        temp = invertTree(root->left);
	        root->left = invertTree(root->right);
	        root->right = temp;
	    }
	    
	    return root;
	}

##Analysis

　　参考了昨天求二叉树最大深度的算法使用了递归，思路差不多。（实在是没什么好写的了，真的很简单╮(￣▽￣")╭  
　　嗯。。此外对于C语言的malloc用法有点不懂吧，如果在定义 `temp` 之后加上：

	temp = malloc(sizeof(struct TreeNode));

　　在 `return` 之前加上：

	free(temp);

　　此时就会报错，无法AC。但只要删除下面的 `free()` 函数，就可以成功AC，也是不太懂它。。。

