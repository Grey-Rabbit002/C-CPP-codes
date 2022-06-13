#include<stdio.h>
#include<stdlib.h>
#include<vector>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
int count=0;
struct node * makeNode(int x){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
void preOrderTraversal(struct node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
void inOrderTraversal(struct node *root){
    if(root!=NULL)
    {
        inOrderTraversal(root->left);
        printf("%d\t",root->data);
        inOrderTraversal(root->right);
    }
}
void postOrderTraversal(struct node *root){
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d\t",root->data);

    }
}

void createTree(struct node **root){
    //will be continously adding elements asssuming with node at root hence it keeps on changing and we do want that change hence we are passing it with reference .
    int choice,x;
    printf("Does left of %d exists or not [1/0]\t",(*root)->data);
    scanf("%d",&choice);

    if(choice==1)
    {
        printf("Enter left node data\t");
        scanf("%d",&x);
        ((*root)->left)=makeNode(x);
        createTree(&(*root)->left);
    }

    printf("Does right of %d exists or not [1/0]\t",(*root)->data);
    scanf("%d",&choice);
    if(choice==1){
        printf("Enter Right node data\t");
        scanf("%d",&x);
        ((*root)->right)=makeNode(x);
        createTree(&(*root)->right);
    }
}
int countNodes(struct node *root){
    if(root!=NULL){
        count++;
        countNodes(root->left);
        countNodes(root->right);
    }
    // if(root!=NULL){
    //     return 1 + countNodes(root->left) + countNodes(root->right);
    // }
    return count;
}
int countLeaves(struct node *root){
    if(root!=NULL)
    {
        if(root->right==NULL && root->right==NULL)
        {
            return 1;
        }
        else
        {
            return countLeaves(root->left) + countLeaves(root->right);
        }
    }
}
int heightTree(struct node *root){
    if(root==NULL){
        return 0;
    }
    else
    {
        int lheight=0;
        int rheight=0;
        if(root->left!=NULL){
            lheight=(1+heightTree(root->left));
        }
        if(root->right!=NULL){
            rheight=(1+heightTree(root->right));
        }
        if(lheight>rheight)
            return lheight;
        else
            return rheight;
    }
}
    int main(){
    struct node *root;
    root=NULL;
    int value;
    printf("Enter value of root node\t");
    scanf("%d",&value);
    root=makeNode(value);
    createTree(&root);//reference call hence address is passed
    printf("\nPre Order Traversal is\t");
    preOrderTraversal(root);
    printf("\nIn Order Traversal is\t");
    preOrderTraversal(root);
    printf("\nPost Order Traversal is\t");
    postOrderTraversal(root);

    int totalnodes=countNodes(root);
    printf("\nTotal Number of Nodes Are\t%d",totalnodes);

    int leaves=countLeaves(root);
    printf("\nTotal Number of LeafNodes Are\t%d",leaves);

    int height=heightTree(root);
    printf("\nHeight of Tree is %d\t\t",height);
    printf("\n");
    // topView(root);
    return 0;
}
