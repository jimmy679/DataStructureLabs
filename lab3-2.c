#include <stdio.h>
#include <malloc.h>
#include <Windows.h>
int n;

typedef struct arcNode
{
    int position;   
    struct arcNode *next;   
}ArcNode, *ArcNode_;

typedef struct vNode
{   
    int mark;   
    ArcNode *first; 
}VNode, *VNode_;

//定义函数 ，构造数

VNode_ Structure()
{   
    VNode_ Chart;   
    int i,k;    
    ArcNode_ p, q;  
    printf("\n请输入要构造的图的顶点总数.\n");   
    scanf("%d", &n);    
    while(n<1)      
    {       
        printf("录入的数据有误！请重新输入。\n");     
        scanf("%d", &n);
    }
    
    Chart = (VNode_)malloc(n*sizeof(VNode));    
    printf("请按照下面的提示构造图。\n\n"); 
    for(i=0; i<n; ++i)      
    {       
        printf("请输入'V%d'指向的所有顶点，结束请输入 0 \n", i+1);      
        scanf("%d", &k);        
        if(k != 0)          
        {           
            q = (ArcNode_)malloc(sizeof(ArcNode));          
            q->position = k-1;          
            (Chart+i)->first = q;           
            p = q;          
            scanf("%d", &k);            
            while(k != 0)               
            {               
                q = (ArcNode_)malloc(sizeof(ArcNode));              
                q->position = k-1;              
                p->next = q;                
                p = q;              
                scanf("%d", &k);                
            }           
            p->next = NULL;         
        }
        
        else            
        {           
            Chart[i].first = NULL;          
        }       
    }   
    return Chart;   
}

//定义函数用于查找

void DFS(VNode_ Chart, int t)
{
    ArcNode_ q; 
    if(Chart[t].mark == 0)      
    {       
        Chart[t].mark = 1;      
        for(q=Chart[t].first; q != NULL; q=q->next)         
        {       
            DFS(Chart, q->position);            
        }       
    }   
}

void Initialize(VNode_ Chart)
{   
    int i;  
    for(i=0; i < n; i++)        
    {       
        (Chart+i)->mark = 0;        
    }   
}

void End(VNode_ Chart)
{   
    int i;  
    ArcNode_ p, q;  
    for(i=0;i<n;i++)    
    {       
        p = Chart[i].first;     
        while(p!=NULL)          
        {       
            q = p;          
            p = p->next;            
            free(q);            
        }       
    }   
    free(Chart);    
}

//定义主函数
int main()
{
    int i=0;    
    int count=0;    
    int w, v;   
    VNode_ Chart = Structure(); 
    while(1){printf("请输入要查询的顶点w,v\n");      
        scanf("%d,%d", &w, &v);     
        DFS(Chart, w-1);        
        if(Chart[v-1].mark)         
        {           
            printf("顶点V%d，与顶点V%d之间连通。", w, v);          
        }       
        else            
        {           
            printf("顶点V%d，与顶点V%d之间不连通。", w, v);         
        }       
        printf("\n\n");     
        End(Chart);}    
}
