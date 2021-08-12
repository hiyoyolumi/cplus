/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void PostOrderTraverse(struct TreeNode *p, int *returnSize, int *arr){
    if(p == NULL)
        return;
    PostOrderTraverse(p->left, returnSize, arr);
    PostOrderTraverse(p->right, returnSize, arr);
    arr[*returnSize] = p->val;
    (*returnSize)++;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    PostOrderTraverse(root, returnSize, arr);
    return arr;    
}