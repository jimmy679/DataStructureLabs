#include <stdio.h>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

void insertElement(SeqList *list, int x) {
    int i, j;
    for (i = 0; i < list->length && list->data[i] < x; i++);
    for (j = list->length; j > i; j--) {    
        list->data[j] = list->data[j - 1];  
    }
    list->data[i] = x;
    list->length++;
}

int main() {
    SeqList myList;
    int size, element;
    printf("请输入顺序表长度: ");
    scanf("%d", &size);
    printf("请以递增的顺序依次输入顺序表中包含的元素:\n");
    for (int i = 0; i < size; i++) {    
        printf("元素 %d: ", i + 1);   
        scanf("%d", &myList.data[i]);   
    }
    myList.length = size;
    printf("输入要插入的元素: ");
    scanf("%d", &element);
    insertElement(&myList, element);
    printf("插入后的顺序表: ");
    for (int i = 0; i < myList.length; i++) {
        printf("%d ", myList.data[i]);
    }
    printf("\n");
    return 0;
}
