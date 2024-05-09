#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <malloc.h>
using namespace std;
typedef struct list
{
    int date;
    struct list *next;
}list,*linklist;
list* l;
void intlist(linklist &l,int n)
{
    l = (linklist)malloc(sizeof(list));
    l->next = l;
    l->date = 1;
    linklist p;
    for (int i = n; i > 1; i--)
    {
        p= (linklist)malloc(sizeof(list));
        p->next = l->next;
        l->next = p;
        p->date = i;
    }
}
void out(linklist l, int s, int m,int n)
{
    list* p = l;
    int i ;
    for (i = 1;; i++)
    {
        if (p->date == s)
        {
            break;
        }
        p = p->next;
    }
    if (m != 1)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j == 1)
            {
                for (int h = 1; h < m - 1; h++)
                {
                    p = p->next;
                }
            }
            else
            {
                for (int h = 1; h < m; h++)
                {
                    p = p->next;
                }
            }
            cout << p->next->date << " ";
            p->next = p->next->next;
        }
    }
    else
    {
        for (int j = 1; j <= n; j++)
        {
            cout << p->date << " ";
            p = p->next;
        }
    }
}
int main()
{
    while (1)
    {
        int n, s, m;
        cout << "依次输入n s m:";
        cin >> n >> s >> m;
        if (n < s||n<=0||s<=0||m<=0)
        {
            cout << "输入错误,请重试!" << endl;
            continue;
        }
        intlist(l, n);
        cout << "输出排序:";
        out(l, s, m, n);
        cout << "\n";
    }
    return 0;
}
