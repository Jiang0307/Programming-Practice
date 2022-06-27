#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

char t1[1000];
char t2[1000];
int input1[200];
int input2[200];
int length1;
int length2;
int count=0;
int height=0;

void print_level_nodes(struct Node* current,int level)
{
    if(current==NULL)
    {
        return;
    }
    else if(level==1)
    {
        if(current->data>0)
        {
            if(count>1)
            {
                printf("%d\n",current->data);
            }
            else
            {
                printf("%d",current->data);
            }
            count--;
        }
    }
    else
    {
        print_level_nodes(current->left,level-1);
        print_level_nodes(current->right,level-1);
    }
}
int tree_height(struct Node* node)
{
    if(node==NULL)
    {
        return 0;
    }
    else
    {
        int left_height=tree_height(node->left);
        int right_height=tree_height(node->right);
        if(left_height>right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height+1;
        }
    }
}

struct Node* Insert(struct Node* root, int num)
{
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=num;
    new_node->left=new_node->right=NULL;
    struct Node* current=root;
    struct Node* parent;

    while(current)
    {
        parent=current;
        if(current->data<num)
        {
            current=current->left;
        }
        else
        {
            current=current->right;
        }
    }

    if(!parent)
        root=new_node;
    else if(num<parent->data)
        parent->left=new_node;
    else if(num>parent->data)
        parent->right=new_node;

    return root;
}

struct Node* Find_MIN(struct Node *root)
{
    if(root == NULL)
    {
        return root;
    }
    else if(root->left!= NULL)
    {
        return Find_MIN(root->left);
    }
    return root;
}
struct Node* Delete(struct Node* root, int num)
{
    if (root == NULL)
    {
        return root;
    }
    if (num < root->data)
    {
        root->left = Delete(root->left,num);
    }
    else if (num > root->data)
    {
        root->right = Delete(root->right,num);
    }
    else
    {
        //0 child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        //1 child
        else if (root->left != NULL && root->right == NULL)
        {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        else if (root->left == NULL && root->right != NULL)
        {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }
        //2 child
        else if (root->left != NULL && root->right != NULL)
        {
            struct Node* temp = Find_MIN(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}
int transfer_input(int num[] , char t1[])
{
   int i=0 , temp=0;
   int index=0;
   while(t1[i]!='\0')
   {
        if(t1[i]==' ')
        {
            num[index++] = temp;
            temp=0;
            i++;
            continue;
        }
        else
        {
            temp*=10;
            temp+=(t1[i++]-'0');
        }
    }
    num[index] = temp;
    index++;
    return index;
}
int main()
{
    struct Node* root = NULL;
    char temp;
    scanf("%[^\r\n]",t1);
    scanf("%c",&temp);
    if(temp=='\r')
    {
        scanf("%c",&temp);
    }
    scanf("%[^\r\n]",t2);
    if(temp=='\r')
    {
        scanf("%c",&temp);
    }
    length1 = transfer_input(input1 , t1);
    length2 = transfer_input(input2 , t2);

    for(int i=0;i<length1;i++)
    {
        root = Insert(root , input1[i]);
        count++;
    }
    for(int i=0 ; i<length2 ; i++)
    {
        if(length2==0)
        {
            break;
        }
        else if(length2>0)
        {
            root = Delete(root , input2[i]);
            if(input2[i]>0)
            {
                count--;
            }
        }
    }
    height=tree_height(root);
    for(int i=1;i<=height;i++)
    {
        print_level_nodes(root,i);
    }
    return 0;
}
