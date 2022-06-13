#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *right;
    struct node *left;
};
struct node *   makeNode(int x){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;//intitaally setting up when a new node is created 
    p->left=NULL;//initially we fill up as in we are doing it for a null node
    p->right=NULL;
    return p;//returning the created node
}
void inOrderTraversal(struct node *root)
{
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d\t",root->data);
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct node *root)
{
    struct node *p=root;
    if(p!=NULL)
    {
        postOrderTraversal(p->left);
        postOrderTraversal(p->right);
                printf("%d\t",p->data);

    }
}
void preOrderTraversal(struct node *root)
{
    struct node *p=root;
    if(p!=NULL)
    {
        printf("%d\t",p->data);
        preOrderTraversal(p->left);
        preOrderTraversal(p->right);
    }
}
void bstInsert(struct node **root,int x)//iterative method for insertion in binarySearchTree
{
    struct node *p,*q;
    p=(*root);
    q=NULL;
    while(p!=NULL)
    {
        q=p;
        if(x<p->data)
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
    else
    {
        q->right=makeNode(x);
    }
    //since this is a like chnage in original is reflected hence we are doing it with pass by reference ...hence double pointer.
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
struct node * bstInsertRecursive(struct node *T,int x)
{
    if(T==NULL)
    {
        T=makeNode(x);
    }
    else
    {
        if(x<T->data)
        {
            T->left=bstInsertRecursive(T->left,x);
        }
        else
        {
            T->right=bstInsertRecursive(T->right,x);
        }
    }
    return T;
}
struct node * binarySearch(struct node *root,int key)
{
    struct node *p=root;
    while(p!=NULL)
    {
        if(p->data=key)
        {
            return p;
        }
        else
        {
            if(key<p->data)
            {
                p=p->left;
            }
            else
            {
                p=p->right;
            }
        }
    }
    return NULL;
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
int main()
{
    printf("Binary Search Trees\n");
    struct node *root;
    root=NULL;
    root=makeNode(100);
    // bstInsert(&root,30);
    // bstInsert(&root,50);
    // bstInsert(&root,120);
    // bstInsert(&root,130);
    // bstInsert(&root,230);
    root=bstInsertRecursive(root,560);
    //recursive method returns the root for every element which is inserted into binary search Tree
    root=bstInsertRecursive(root,102);
    root=bstInsertRecursive(root,180);
    root=bstInsertRecursive(root,210);
    root=bstInsertRecursive(root,510);
    root=bstInsertRecursive(root,140);
    root=bstInsertRecursive(root,10);
    printf("\n");
    inOrderTraversal(root);
    printf("\n");
    maxofTree(root);
    printf("\n");
    minofTree(root);
    struct node *search=NULL;
    search=binarySearchRecursive(root,30);
    printf("\n\%d\t found",search->data);
    return 0;
}