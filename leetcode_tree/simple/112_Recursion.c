/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool PreOrderTraverse(struct TreeNode *p, int targetSum, int *sum){
    if(p == NULL)
        return false;
    *sum += p->val;
    if((*sum == targetSum) && (p->left == NULL && p->right == NULL))
        return true;
    // if(p->left == NULL && p->right == NULL)
    //     *sum -= p->val;
    if(PreOrderTraverse(p->left, targetSum, sum) == true)
        return true;
    if(PreOrderTraverse(p->right, targetSum, sum) == true)
        return true;
    *sum -= p->val;
    return false;
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    int sum = 0;
    return PreOrderTraverse(root, targetSum, &sum);
}