/* BINARY SEARCH TREE POSTLAB 11 */
#include <stdio.h>
#include <stdlib.h>
typedef struct BST1
{
    int data;
    struct BST1 *left,*right;
}node;

node *create(int data)
{
    node *newnode;
    newnode=(node *)malloc(sizeof(node));
    newnode->data=data;
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
node* search(node *root,int key)
{
    if(root->data==key)
        return root;
    else if(key<root->data)
        search(root->left,key);
    else if(key>root->data)
        search(root->right,key);
    else
        return NULL;
}
node* pre(node *root,node *tofind)
{
    node *pre=NULL;
    if(tofind->left)
    {
        pre=tofind->left;
        while(pre->right)
            pre=pre->right;
    }
    else
    {
        while(root)
        {
            if(tofind->data<root->data)
            {
                root=root->left;
            }
            else if(tofind->data>root->data)
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
int child(node *root)
{
    static int count=0;
    if(root->left)
    {
        count++;
        count=child(root->left);
    }
    if(root->right)
    {
        count++;
        count=child(root->right);
    }
    return count;
}
int main()
{
    node *root=NULL,*newnode;
    node *x,*y;
    int n,i,a,key,c;
    node *create(int data);
    void insert(node *root,node *newnode);
    node* search(node *root,int key);
    node* pre(node *root,node *tofind);
    int child(node *root);
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        newnode=create(a);
        if(root==NULL)
            root=newnode;
        insert(root,newnode);
    }
    scanf("%d",&key);
    x=search(root,key);
    if(x==NULL)
        printf("Key not found");
    else
    {
        y=pre(root,x);
    }
    if(y!=NULL)
    {
        printf("%d",y->data);
        c=child(y);
        printf("\n%d",c);
    }
    else
        printf("No such value is present");
    return 0;

}
