#include<stdio.h>
#include<malloc.h>
#include<conio.h>
typedef struct VNode
{
    int info;
    struct VNode *next_node;
}Node;
void input(Node*head, int number)
{
    if(number!=0)
    {
        int i;
        Node *t;
        t=(Node *)malloc(sizeof(Node));
        head->next_node=t;
        scanf("%d",&i);
        t->info=i;
        input(t,number-1);
    }
}
void output(Node*head, int count)
{
    Node *t;
    if(count!=0)
    {
        t=head->next_node;
        printf("%d ",t->info);
        output(t,count-1);
    }
}
void select(Node*head, int num)
{
    int tem=0;
    if(num!=0)
    {
        int min_node;
        Node *t;
        Node *r;
        Node *q;
        t=head->next_node;
        r= head->next_node;
        q=head;
        min_node= t->info;
        for(int i=0;i<num;i++)
        {
            if(min_node>t->info)
            {
                min_node= t->info;
                r=t;
                tem=i;
            }
            t=t->next_node;
        }
        for(int j=0;j<tem;j++)
            q=q->next_node;
        q->next_node=r->next_node;
        r->next_node=head->next_node;
        head->next_node=r;
        select(head->next_node,num-1);
    }
}
int main()
{
    int num;
    Node *head;
    head=( Node *)malloc(sizeof(Node));
    printf("请输入链表总长度：");
    scanf("%d",&num);
    printf("请输入要排序的数据：\n");
    input(head,num);
    printf("\n经过选择排序后的序列为：\n");
    select(head,num);
    output(head,num);
    getch();}
