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
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int *arr = (int *)malloc(sizeof(int) * 100);
    *returnSize = 0;
    if(root == NULL)
        return arr;
    int top = 0;
    struct TreeNode *stack[100];
    struct TreeNode *prev = NULL;
    while(root != NULL || top > 0){
        while(root != NULL){
            stack[top] = root;
            top++;
            root = root->left;
        }
        top--;
        root = stack[top];
        if(root->right == NULL || root->right == prev){
            arr[*returnSize] = root->val;
            (*returnSize)++;
            prev = root;
            root = NULL;
        }
        else{
            stack[top] = root;
            top++;
            root = root->right;
        }
    }
    return arr;
}