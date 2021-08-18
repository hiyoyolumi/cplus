/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void PreOrder(struct TreeNode *p, int *flag, int *sum){
    if (p->left == NULL && p->right == NULL && flag == 1) {
        return;
    } else if (p->left == NULL && p->right == NULL && flag == 0) {
        (*sum) += p->val;
        return;
    }
    PreOrder(p->left, 0, sum);
    PreOrder(p->right, 1, sum);
}

int sumOfLeftLeaves(struct TreeNode* root){
    int flag = 0;
    int sum = 0;
    PreOrder(root, &flag, &sum);
    return sum;
}