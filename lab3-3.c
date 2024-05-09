#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 20

typedef struct ArcNode {    
    int adjvex; 
    struct ArcNode *nextarc;    
} ArcNode;

typedef struct {    
    int info; 
    bool mark;      
    int pre;          
    ArcNode *out;      
} VertexNode;

typedef struct {
    VertexNode nodelist[MAX_VERTEX_NUM];  
    int vexnum, arcnum;                   
} ALGraph;

void CreateALGraph(ALGraph *G) {    
    printf("输入顶点个数: "); 
    scanf("%d", &G->vexnum);    
    G->arcnum = 0;  
    for (int i = 0; i < G->vexnum; ++i) {       
        printf("输入顶点 %d 的值: ", i);      
        scanf("%d", &G->nodelist[i].info);      
        G->nodelist[i].mark = false;        
        G->nodelist[i].pre = -1;    
        G->nodelist[i].out = NULL;  
    }
    
    int start, end; 
    while (1) {     
        printf("输入有向边 (输入负值结束): ");     
        scanf("%d", &start);        
        if (start < 0) {            
            break;          
        }       
        scanf("%d", &end);      
        ArcNode *arc = (ArcNode *)malloc(sizeof(ArcNode));      
        arc->adjvex = end;      
        arc->nextarc = G->nodelist[start].out;      
        G->nodelist[start].out = arc;       
        G->arcnum++;        
    }   
}

bool DFS(ALGraph *G, int start, int target) {   
    G->nodelist[start].mark = true; 
    if (start == target) {      
        return true;        
    }
    
    ArcNode *p = G->nodelist[start].out;    
    while (p != NULL) {     
        if (!G->nodelist[p->adjvex].mark && DFS(G, p->adjvex, target)) {            
            G->nodelist[p->adjvex].pre = start;         
            return true;            
        }       
        p = p->nextarc;     
    }   
    return false;   
}

bool hasPath(ALGraph *G, int start, int target) {   
    for (int i = 0; i < G->vexnum; ++i) {       
        G->nodelist[i].mark = false;        
        G->nodelist[i].pre = -1;        
    }   
    return DFS(G, start, target);   
}

int main() {    
    ALGraph G;  
    CreateALGraph(&G);  
    int start, target;  
    printf("输入起始顶点和目标顶点 (用空格分隔): ");    
    scanf("%d %d", &start, &target);    
    if (hasPath(&G, start, target)) {       
        printf("存在路径从顶点 %d 到顶点 %d\n", start, target);
        printf("路径: %d", target);       
        int pre = G.nodelist[target].pre;       
        while (pre != -1) {         
            printf(" <- %d", pre);          
            pre = G.nodelist[pre].pre;          
        }       
        printf("\n");       
    } else {        
        printf("不存在路径从顶点 %d 到顶点 %d\n", start, target);      
    }   
    return 0;   
}

