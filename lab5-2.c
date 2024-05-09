#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int x;
    struct node *next;
}Node;
void Read(Node *head,int n);// 
void Show(Node *head,int n);
void Sort(Node *head,int n);
int main(){
    int n;
    Node *head;
    head=(Node *)malloc(sizeof(Node));
    printf("输入元素总数:");
    scanf("%d",&n);
    printf("输入%d个数据:\n",n);
    Read(head,n);
    printf("排序后的数据为:\n");
    Sort(head,n);
    Show(head,n);
    return 0;
}
void Read(Node *head,int n){
    if(n==0)
        return;
    int x;
    Node *p;
    p=(Node*)malloc(sizeof(Node));
    p->next=NULL;
    head->next=p;
    scanf("%d",&x);
    p->x=x;
    Read(p,n-1);
}
void Show(Node *head,int n){
    Node *p;
    if(n==0)
        return;
    p=head->next;
    printf("%d ",p->x);
    Show(p,n-1);
}
void Sort(Node *head,int n){
    int i;
    Node *p;
    Node *r;
    Node *t;
    p=head->next->next;
    r=head->next->next;
    t=head->next;
    for(i=1;i<n;i++){
        if(p->x>=0){
            r=p;
            t->next=r->next;
            r->next=head->next;
            head->next=r;
            p=t->next;
        }
        else{
            p=p->next;
            t=t->next;
        }
    }
}
