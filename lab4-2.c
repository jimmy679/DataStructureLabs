#include <bits/stdc++.h>
int Search(int* a, int k, int low, int hight)
{   
    int mid;
    if (low > hight)        
    {       
        return 0;       
    }   
    mid = (low + hight) / 2;    
    if (a[mid] == k)        
    {       
        return (mid + 1);       
    }   
    else if (a[mid] > k)        
    {       
        return Search(a, k, low, mid - 1);      
    }   
    else        
    {       
        return Search(a, k, mid + 1, hight);        
    }   
}

int main()
{   
    int i, n, key, position;    
    printf("你有多少个数据要输入：\n");    
    scanf("%d", &n);    
    int p[n];   
    printf("请按递增序列输入你的数据（整型变量）：\n");    
    scanf("%d", &p[0]); 
    for (i = 1; i < n; i++)     
    {       
        scanf("%d", &p[i]);     
        while (p[i] < p[i - 1])     
        {       
            printf("你输入的数据不合理，请重新输入：\n");       
            scanf("%d", &p[i]);     
        }   
    }
    printf("请输入你要查找的数据：\n");    
    scanf("%d", &key);  
    position = Search(p, key, 0, n - 1);    
    if (position == 0)      
    {       
        printf("没有找到你要查找的数据！\n");       
    }   
    else        
    {   
        printf("你所查找的数据位于原有序表的第%d个位置！\n", position);    
    }   
    return 0;   
}
