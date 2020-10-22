#include<stdio.h>
#include<stdlib.h>
  
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(value){
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}
  
  
struct node* insert(struct node* root, int data)
{
    if (root == NULL) 
    return createNode(data);

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);   
 
    return root;
}

void inorder(struct node* root)
{
    if(root == NULL)
    return;
        printf("\n");
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
}

void preorder(struct node* root)
{
    if(root == NULL) 
    return;
        printf("\n");
	printf("%d ->", root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root == NULL) 
    return;
        printf("\n");
    inorder(root->left);
    inorder(root->right);
    printf("%d ->", root->data);
}

void main(){
    struct node *root = NULL;
    int x,y;
    printf("enter data");
    scanf("%d",&x);

	root = insert(root, x);
    printf("want to repeat");
	scanf("%d",&y);    
	while(y)
	{
    printf("enter data");
    scanf("%d",&x);

	insert(root, x);
	printf("want to repeat");
	scanf("%d",&y);     
	}
    inorder(root);
    preorder(root);
    postorder(root);
}
