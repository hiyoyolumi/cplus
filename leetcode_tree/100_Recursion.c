/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int flag;

void PreOrderTraverse(struct TreeNode* p, struct TreeNode* q){
    if(flag == 1)
        return;
    if(p == NULL && q == NULL)
        return;
    if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
        flag = 1;
        return;
    }
    if(p->val != q->val){
        flag = 1;
        return;
    }
    PreOrderTraverse(p->left, q->left);
    PreOrderTraverse(p->right, q->right);
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    flag = 0;    
    PreOrderTraverse(p, q);
    if(flag == 0)
        return true;
    else
        return false;
}