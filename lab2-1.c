#include<stdio.h>
#define N 1000
char a[N];
int i=1,k;
typedef struct node{
    char data;
    struct node * lchild;
    struct node * rchild; 
}BiTree;
 
BiTree * CreatTree();
int Count(BiTree * );//叶子节点 
void Preorder(BiTree * );//先序遍历 
void Middleorder(BiTree * );//中序遍历 
void Postorder(BiTree * );//后序遍历 
void getNode(BiTree * );//递归算法，在二叉树中求位于先序序列中第K个位置的结点
 
int main(){
    printf("请以先序序列输入一颗二叉树，空以#代替\n"); 
    BiTree * top = NULL;
    top = CreatTree();

    printf("先序遍历结果: ");
    Preorder(top);
    printf("\n");
    
    printf("中序遍历结果: ");
    Middleorder(top);
    printf("\n");
    
    printf("后序遍历结果: ");
    Postorder(top);
    printf("\n");
    
    putchar('\n');
    printf("叶子节点的个数为: %d\n",Count(top));
    printf("请输入要查找的节点位置: ");
    scanf("%d",&k);
    printf("第%d个位置的节点为: ",k);
    getNode(top);
    printf("%c\n",a[k]);
    return 0;
    
}
 
BiTree * CreatTree(){
    BiTree *t;
    char ch;
    ch = getchar();
    if(ch != '#'){
        t=(BiTree *)malloc(sizeof(BiTree));
        t->data=ch;//先序遍历根左右，空由#代替 
        t->lchild=CreatTree();
        t->rchild=CreatTree();
    }
    else{
        t=NULL;
    }
    return t;
}
int Count(BiTree * top){
    if(top==NULL){
        return 0;
    }
    else if((top->lchild==NULL)&&(top->rchild==NULL)){//递归出口，若左右孩子皆空则为叶子节点 
        return 1;
    }
    else {
        return Count(top->lchild)+Count(top->rchild);
    }
}
 
void Preorder(BiTree *top){
    if(top!=NULL){//不空则先序遍历 
        printf("%c",top->data);
        Preorder(top->lchild);
        Preorder(top->rchild);
    }
}
 
void Middleorder(BiTree *top){
    if(top!=NULL){//不空则中序遍历 
        Middleorder(top->lchild);
        printf("%c",top->data);
        Middleorder(top->rchild);
    }
}
 
void Postorder(BiTree *top){
    if(top!=NULL){//不空则后序遍历 
        Postorder(top->lchild);
        Postorder(top->rchild);
        printf("%c",top->data);
    }
}
 
void getNode(BiTree *t){
    if(t){//不空则遍历根左右 
        a[i]=t->data;
        i++;
        getNode(t->lchild);
        getNode(t->rchild);
    }
}
