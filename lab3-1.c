#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 20

typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
} ArcNode;

typedef struct VNode {
    int data;
    ArcNode *firstarc;
} VNode;

typedef struct {
    VNode adjlist[MAX_VERTEX_NUM];
    int vexnum, arcnum;
} ALGraph;

void CreateALGraph(ALGraph *G) {
    printf("输入顶点数: ");
    scanf("%d", &G->vexnum);
    G->arcnum = 0;
    for (int i = 0; i < G->vexnum; ++i) {
        printf("输入顶点 %d 的值: ", i);
        scanf("%d", &G->adjlist[i].data);
        G->adjlist[i].firstarc = NULL;
    }
    
    int start, end;
    while (1) {
        printf("输入边 (输入 -1 结束): ");
        scanf("%d", &start);
        if (start == -1) {  
            break;  
        }
        scanf("%d", &end);
        ArcNode *arc1 = (ArcNode *)malloc(sizeof(ArcNode));
        arc1->adjvex = end;
        arc1->nextarc = G->adjlist[start].firstarc;
        G->adjlist[start].firstarc = arc1;
        ArcNode *arc2 = (ArcNode *)malloc(sizeof(ArcNode));
        arc2->adjvex = start;
        arc2->nextarc = G->adjlist[end].firstarc;
        G->adjlist[end].firstarc = arc2;
        G->arcnum += 2;
    }
}

void DFS(ALGraph *G, int v, bool visited[]) {
    visited[v] = true;
    ArcNode *p = G->adjlist[v].firstarc;
    while (p != NULL) {
        if (!visited[p->adjvex]) {
            DFS(G, p->adjvex, visited);
        }
        p = p->nextarc;
    }
}

int CountConnectedComponents(ALGraph *G) {
    bool visited[MAX_VERTEX_NUM];
    int count = 0;
    for (int i = 0; i < G->vexnum; ++i) {
        visited[i] = false;
    }
    
    for (int i = 0; i < G->vexnum; ++i) {
        if (!visited[i]) {
            DFS(G, i, visited);
            count++;
        }
    }   
    return count;   
}

int main() {    
    ALGraph G;
    CreateALGraph(&G);  
    int connectedComponents = CountConnectedComponents(&G); 
    printf("连通分量个数: %d\n", connectedComponents);    
    return 0;   
}
