#include <stdio.h>
#include <stdlib.h>
#define ENDKEY 0
typedef int KeyType;
typedef struct  node
{
    KeyType  key ;
    struct node  *lchild,*rchild;
}BSTNode, *BSTree;

void InsertBST(BSTree *bst, KeyType key)
{   
    BSTree s;
    if (*bst == NULL)       
    {       
        s=(BSTree)malloc(sizeof(BSTNode));      
        s-> key=key;        
        s->lchild=NULL;     
        s->rchild=NULL;     
        *bst=s;     
    }   
    else        
        if (key < (*bst)->key)          
            InsertBST(&((*bst)->lchild), key);
    else        
        if (key > (*bst)->key)          
            InsertBST(&((*bst)->rchild), key); 
}

void  CreateBST(BSTree  *bst)
{   
    KeyType key;    
    *bst=NULL;  
    scanf("%d", &key);  
    while (key!=ENDKEY)  
    {       
        InsertBST(bst, key);        
        scanf("%d", &key);      
    }   
}

void  PreOrder(BSTree root)
{   
    if (root!=NULL)     
    {       
        PreOrder(root->lchild);         
        printf("%d  ",root->key);       
        PreOrder(root->rchild);  
    }
}

BSTree  SearchBST(BSTree bst, KeyType key)
{   
    BSTree q;   
    q=bst;  
    while(q)        
    {       
        if (q->key == key)          
            return q;  
        if (q->key > key)   
            q=q->lchild;  
        else    
            q=q->rchild;  
    }   
    return NULL;    
}

int main()
{   
    BSTree T;
    int k;
    BSTree result;
    printf("建立二叉排序树，请输入序列以0结束:\n");
    CreateBST(&T);
    printf("先序遍历输出序列为:");
    PreOrder(T);    
    printf("\n请输入要查找的元素:"); 
    fflush(stdin);  
    scanf("%d",&k); 
    result = SearchBST(T,k);    
    if (result != NULL)     
        printf("已查到");
    else        
        printf("未找到!\n");   
}
