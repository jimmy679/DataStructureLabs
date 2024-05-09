#include<stdio.h>
    #include<stdlib.h>
    typedef struct list{
        int c;
        int e;
        struct list *next;
    }list,*Linklist;
    
    Linklist creatPolyn(){
        Linklist  head,p,q;
        int m;
        head = (Linklist)malloc(sizeof(list));
        head->next= NULL;
        q = head;
        printf("请输入多项式的项数：");
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            p = (Linklist)malloc(sizeof(list));
            printf("输入第%d项的系数：",i+1);
            scanf("%d",&p->c);
            printf("输入第%d项的指数：",i+1);
            scanf("%d",&p->e);
            p->next = q->next;
            q->next = p;
            q = q->next;
        }
        return head;
    }
    Linklist AddPolyn(Linklist pa,Linklist pb){
        Linklist a,b,pc,c;
        a = pa;        
b = pb;        
c = (Linklist)malloc(sizeof(list)); 
c->next = NULL;  
        pc = c;
        while(a&&b){
            int m,n,sum;
            m=a->e; n=b->e;
            if(m>n){
                pc->next = b;
                pc = pc->next;
                b = b->next;
             }
            
            else if(m == n){
                sum = a->c + b->c;
                if(sum!=0){
                    a->c = sum;
                    pc->next = a;
                    pc=pc->next;
                  }
                
                a = a->next;
                b = b->next;
            }
            
            else{
                pc->next = a;
                pc = pc->next;
                a = a->next;
             }
            
        }
        if(a!=NULL){
            pc->next = a;
        }
        
        if(b!=NULL){
            pc->next = b;
        }
        
        return c;
    }
    
    void printList(Linklist L){
        while(L != NULL){
            printf("%d*X^%d ",L->c,L->e);
            L = L->next;
        }
        
        printf("\n");
    }
    
    int main(){
        Linklist pa,pb,pc;
        printf("请输入第一个多项式的系数和指数\n");
        pa = creatPolyn();
        printf("请输入第二个多项式的系数和指数\n");
        pb = creatPolyn();
        printf("输入的第一个多项式是：\n");
        printList(pa->next);
        printf("输入的第二个多项式是:\n");
        printList(pb->next);
        pc = AddPolyn(pa->next,pb->next);
        printf("两个多项式的和为：");
        printList(pc->next);
        return 0;
    }
