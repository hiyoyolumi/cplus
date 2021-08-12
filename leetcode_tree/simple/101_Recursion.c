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
    PreOrderTraverse(p->left, q->right);
    PreOrderTraverse(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
    flag = 0;
    PreOrderTraverse(root, root);
    if(flag == 1)
        return false;
    else
        return true;
}