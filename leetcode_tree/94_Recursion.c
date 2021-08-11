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

void InOrderTraver(struct TreeNode *T, int *arr, int *returnSize)
{
    if(T == NULL)
        return;
    InOrderTraver(T->left, arr, returnSize);
    arr[*returnSize] = T->val;
    (*returnSize)++;
    InOrderTraver(T->right, arr, returnSize); 
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    InOrderTraver(root, arr, returnSize);
    return arr;
}