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
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    int top = 0;
    struct TreeNode *stack[100];
    while(root != NULL || top > 0){
        while(root != NULL){
            arr[*returnSize] = root->val;
            (*returnSize)++;
            stack[top] = root;
            top++;
            root = root->left;
        }
        top--;
        root = stack[top];
        root = root->right;
    }
    return arr;
}