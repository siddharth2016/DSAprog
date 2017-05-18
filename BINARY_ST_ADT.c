/* BINARY SEARCH TREE ADT'S */
#include <stdio.h>
#include <stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left,*right;
}node;
node *create(int key)
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=key;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void insert(node *root,node *newnode)
{
    if(newnode->data<root->data)
    {
        if(root->left==NULL)
            root->left=newnode;
        else
            insert(root->left,newnode);
    }
    if(newnode->data>root->data)
    {
        if(root->right==NULL)
            root->right=newnode;
        else
            insert(root->right,newnode);
    }
}
node *successor(node *root,node *key)
{
    node *succ=NULL;
    if(root==NULL)
        return NULL;
    if(key->right!=NULL)
    {
        succ=key->right;
        while(succ->left)
            succ=succ->left;
    }
    else
    {
        while(root)
        {
            if(key->data<root->data)
            {
                succ=root;
                root=root->left;
            }
            else if(key->data>root->data)
                root=root->right;
            else
                break;
        }
    }
    return succ;
}
node *predecessor(node *root,node *key)
{
    node *pre=NULL;
    if(root==NULL)
        return NULL;
    if(key->left!=NULL)
    {
        pre=key->left;
        while(pre->right)
            pre=pre->right;
    }
    else
    {
        while(root)
        {
            if(key->data<root->data)
                root=root->left;
            else if(key->data>root->data)
            {
                pre=root;
                root=root->right;
            }
            else
                break;
        }
    }
    return pre;
}
void inorder(node *root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}
void preorder(node *root)
{
    if(root)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(node *root)
{
    if(root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
node *deletee(node *root,int data)
{
    node *temp;
    if(root==NULL)
        return NULL;
    else if(data<root->data)
        root->left=deletee(root->left,data);
    else if(data>root->data)
        root->right=deletee(right->right,data);
    else
    {
        if(root->left && root->right)
        {
            temp=predecessor(root,root);
            root->data=temp->data;
            root->left=deletee(root->left,root->data);
        }
        else
        {
            temp=root;
            if(root->left==NULL)
                root=root->right;
            if(root->right==NULL)
                root=root->left;
            free(temp);
        }
    }
    return root;
}
int main()
{
    int choice,n,i;
}
