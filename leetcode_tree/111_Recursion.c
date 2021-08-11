/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void PreOrderTraverse(struct TreeNode* p, int *num, int *min){
    if(p == NULL){
        return;
    }
    (*num)++;
    if(p->left == NULL && p->right == NULL){
        if(*min == 0)
            *min = *num;
        if(*min > *num)
            *min = *num;
    }
    PreOrderTraverse(p->left, num, min);
    PreOrderTraverse(p->right, num, min);
    (*num)--;
}

int minDepth(struct TreeNode* root){
    int num = 0;
    int min = 0;
    PreOrderTraverse(root, &num, &min);
    return min;
}