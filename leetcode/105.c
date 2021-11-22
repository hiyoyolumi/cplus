// 105. 从前序与中序遍历序列构造二叉树
// 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。

 

// 示例 1:


// Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
// Output: [3,9,20,null,null,15,7]
// 示例 2:

// Input: preorder = [-1], inorder = [-1]
// Output: [-1]


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* CreateByPI(int *preorder, int *inorder, int n) {
    if (n <= 0) {
        return NULL;
    }
    struct TreeNode *s;
    int pos;
    int *p;
    s = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    s->val = *preorder;
    for (p = inorder; p < inorder + n; p++) {
        if (*p == *preorder) {
            break;
        }
    }
    pos = (p-inorder);
    s->left = CreateByPI(preorder+1, inorder, pos);
    s->right = CreateByPI(preorder+pos+1, p+1, n-pos-1);
    return s;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    return CreateByPI(preorder, inorder, preorderSize);
}