/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void PreOrderTraverse(struct TreeNode* p, int* num, int* max){
    if(p == NULL){
        return;
    }
    (*num)++;
    if(*max < *num)
        *max = *num;
    PreOrderTraverse(p->left, num, max);
    PreOrderTraverse(p->right, num, max);
    (*num)--;
}

int maxDepth(struct TreeNode* root){
    int max = 0;
    int num = 0;
    PreOrderTraverse(root, &num, &max);
    return max;
}