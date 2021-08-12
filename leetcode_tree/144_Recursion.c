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

void PreOrderTraverse(struct TreeNode *p, int *arr, int *returnSize){
    if(p == NULL)
        return;
    arr[*returnSize] = p->val;
    (*returnSize)++;
    PreOrderTraverse(p->left, arr, returnSize);
    PreOrderTraverse(p->right, arr, returnSize);
}   

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    PreOrderTraverse(root, arr, returnSize);
    return arr;
}