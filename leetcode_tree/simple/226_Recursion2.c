/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void InOrderTraverse(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q){
    if (p == NULL && q == NULL) {
        return;
    }
    if (p != NULL && q != NULL) {
        InOrderTraverse(root->left, root->left->left, root->left->right);
        InOrderTraverse(root->right, root->right->left, root->right->right);
    } else if (p != NULL && q == NULL) {
        InOrderTraverse(root->left, root->left->left, root->left->right);
    } else if (p == NULL && q != NULL) {
        InOrderTraverse(root->right, root->right->left, root->right->right);
    }
    root->left = q;
    root->right = p;
}

struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) {
        return root;
    }
    InOrderTraverse(root, root->left, root->right);
    return root;
}