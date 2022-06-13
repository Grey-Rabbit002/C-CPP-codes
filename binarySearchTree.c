#include<stdio.h>
#include<stdlib.h>
struct  node{
    int data;
    struct node *left;
    struct node *right;
    int h;
};
struct node * makeNode(int x)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->right=NULL;
    p->left=NULL;
    p->data=x;
    p->h=0;
    return p;
}
void inOrderTraversal(struct node *root)
{
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf("\t%d",root->data);
        inOrderTraversal(root->right);
    }
}
void bstInsert(struct node **root,int x)
{
    struct node *p,*q;
    p=(*root);
    q=NULL;
    while (p!=NULL)
    {
        q=p;
        if (x<p->data)
        {
            p=p->left;
        }
        else
        {
            p=p->right;
        }
    }
    if(x<q->data)
    {
        q->left=makeNode(x);
    }
    else{
        q->right=makeNode(x);
    }
}
void minofTree(struct node *root)
{
    struct node *p,*q;
    p=root;
    while(p!=NULL)
    {
        q=p;
        p=p->left;
    }
    printf("minimum data is \t%d",q->data);

}
void maxofTree(struct node *root)
{
    struct node *p,*q;
    p=root;
    while(p!=NULL)
    {
        q=p;
        p=p->right;
    }
    printf("maximum data is \t%d",q->data);

}
struct node * bstRecursiveInsert(struct node *root,int x)
{
    struct node *t=root;
    if(t==NULL)
    {
        t=makeNode(x);
    }
    else
    {
        if(x<t->data)
        {
            t->left=bstRecursiveInsert(t->left,x);
        }
        else
        {
            t->right=bstRecursiveInsert(t->right,x);
        }
    }
    t->h=1;//change this height updation statement currently this is wrong...and approach would be taking a fayher and then moving up indrectly in a recursive way ...hence we avoid the iterative method
    return t;
}
struct node * binarySearchRecursive(struct node *root,int key)
{
    struct node *t=root;
    if(t!=NULL)
    {
        if(t->data==key)
        {
            return t;
        }
        else
        {
            if(key<t->data)
            {
                binarySearchRecursive(t->left,key);
            }
            else
            {
                binarySearchRecursive(t->right,key);
            }
        }
    }
    else
    {
        return NULL;
    }
}
int heightTree(struct node *root)
{
    int hl=0,hr=0;
    if(root->left==NULL){
        hl=0;
    }
    else
    {
        hl=1+root->left->h;
    }
    if(root->right==NULL)
    {
        hr=0;
    }
    else
    {
        hr=1+root->right->h;
    }
    //maximum of the above
    if(hl>hr)
    {
        return hl;
    }
    else
    {
        return hr;
    } 
}
int balanceFactor(struct node *root)
{
    int hl=0,hr=0;
    if(root->left==NULL){
        hl=0;
    }
    else
    {
        hl=1+root->left->h;
    }
    if(root->right==NULL)
    {
        hr=0;
    }
    else
    {
        hr=1+root->right->h;
    }
    return hl-hr;
}
struct node * rotateLeft(struct node *x)
{
    struct node *y,*z;
    y=x->right;
    z=y->left;
    y->left=x;
    x->right=z;

    return y;
}
struct node * rotateRight(struct node *x)
{
    struct node *y,*z;
    y=x->left;
    z=y->right;
    y->right=x;
    x->left=z;

    return y;
}
struct node * ll(struct node *x)
{
    struct node *y;
    y=rotateRight(x);

    return y;
}
struct node * rr(struct node *x)
{
    struct node *y;
    y=rotateLeft(x);

    return y;
}
struct node *lr(struct node *x)
{
    struct node *y,*w,*z;
    y=x->left;
    z=rotateLeft(y);
    x->left=z;
    w=rotateRight(x);//new node that is returned
}
struct node *rl(struct node *x)
{
    struct node *y,*w,*z;
    y=x->right;
    z=rotateRight(y);
    x->right=z;
    w=rotateLeft(x);

    return w;
}
struct node * avlInsert(struct node *root,int x)
{
    struct node *t=root;
    if(t==NULL)
    {
        t=makeNode(x);
    }
    else
    {
        if(x<t->data)
        {
            t->left=bstRecursiveInsert(t->left,x);
            if(balanceFactor(t)==2)
            {
                if(x<t->left->data)
                {
                    t=ll(t);//taking in as same name 
                }
                else
                {
                    t=lr(t);
                }
            }       
        }
        else
        {
            t->right=bstRecursiveInsert(t->right,x);
            if(balanceFactor(t)==-2)
            {
                if(x>t->right->data)
                {
                    t=rr(t);//taking in as same name 
                }
                else
                {
                    t=rl(t);
                }
            }       
        }
    }
    t->h=heightTree(t);
    return t;
}
int main()
{
    // printf("0");
    struct node *root;
    root=NULL;
    root=makeNode(100);
    // bstInsert(&root,50);
    // bstInsert(&root,150);
    // bstInsert(&root,20);
    // bstInsert(&root,40);
    // bstInsert(&root,110);
    // bstInsert(&root,70);
    // bstInsert(&root,200);
    avlInsert(root,100);
    avlInsert(root,150);
    avlInsert(root,120);
    // avlInsert(&root,);
    // avlInsert(&root,);
    // avlInsert(&root,);
    // avlInsert(&root,);

    //***************************************************//
    // root=bstRecursiveInsert(root,100);
    // root=bstRecursiveInsert(root,50);
    // root=bstRecursiveInsert(root,30);
    // root=bstRecursiveInsert(root,50);
    // root=bstRecursiveInsert(root,110);
    // // printf("0");
    //******************************************************//
    inOrderTraversal(root);
    printf("\n");
    maxofTree(root);
    printf("\n");
    minofTree(root);
        // printf("0");

    return 0;
}