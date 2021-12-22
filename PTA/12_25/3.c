BiTree PreInCreate(int a[],int b[],int l1,int h1,int l2,int h2){
	BiTNode *root=(BiTNode *)malloc(sizeof(BiTNode));
	root->data=a[l1];//在先序序列中找到root 
	for(int i=l1;b[i]!=root->data;i++);//找到root在中序序列中的位置 
	int llen=i-l2;//划分为左右部分（不含该root） 
	int rlen=h2-i;
	if(len)      //递归建立左右子树 
       root->lchild=PreInCreate(a,b,l1+1,l1+llen,l2,l2+llen-1);//先序和中序遍历中的左子树界限 
    else
       root->lchild=NULL;
    if(rlen)
       root->rchild=PreInCreate(a,b,h1-rlen+1,h1,h2-rlen+1,h2);//先序和中序遍历中的右子树界限 
    else
       root->rchild=NULL;
    return root;
}