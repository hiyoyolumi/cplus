/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void PreOrderTraverse(struct TreeNode *p, int *num, int *max){
    if(p == NULL)
        return;
    (*num)++;
    if(*max < *num)
        *max = *num;
    PreOrderTraverse(p->left, num, max);
    PreOrderTraverse(p->right, num, max);
    (*num)--;
}

bool isBalanced(struct TreeNode* root){
    if(root == NULL)
        return true;
    if(root->left == NULL && root->right == NULL)
        return true;
    if(isBalanced(root->left) == false)
        return false;
    if(isBalanced(root->right) == false)
        return false;
    int num = 0;
    int lmax = 0, rmax = 0;
    PreOrderTraverse(root->left, &num, &lmax);
    num = 0;
    PreOrderTraverse(root->right, &num, &rmax);
    if(lmax - rmax > 1 || rmax - lmax > 1)
        return false;
    return true;
}